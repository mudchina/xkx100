// /cmds/arch/checkcoor.c

// Created by Constant Jan 7 2001
inherit F_CLEAN_UP;

#define COOR_LOG "/log/static/COOR_LOG"



string *base_room = ({
	"inherit BANK"
	"inherit HOCKSHOP"
	"inherit \"/inherit/room/pigroom.c\"",
	"inherit ROOM",
});

int file_count;
int recur_check(object me, string file, int recur);
int check_one_file(object me,string file);

int main(object me, string arg)
{
	string dir;
	int recur = 0;

	seteuid(geteuid(me));
	file_count = 0;
	write_file(COOR_LOG, "", 1);

	if (arg == "-s") {
		recur = 1;
		arg = "";
	}

	if (arg && sscanf(arg, "-d %s", arg))
		recur = 1;

	dir = resolve_path(me->query("cwd"), arg);

	recur_check(me ,dir, recur);
	
	if (file_count) {
		write("\n共处理" + file_count + "个文件。\n");
		write("结果已写入" + COOR_LOG + "中，请查看。\n");
	} else
		write("\n未检测到不合要求的文件。\n");

	return 1;
}

int recur_check(object me, string dir, int recur)
{
	int i, j;
	mixed *file;
	
	if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/')
		dir += "/";

	file = get_dir(dir, -1);

	if (!sizeof(file)) {
		if (file_size(dir) == -2)
			return notify_fail("目录是空的。\n");
		else
			return notify_fail("没有这个目录。\n");
	}

	i = sizeof(file);
	while (i --) {
		if (file[i][1] == -2)
			file[i][0] += "/";
	}

	write("\n正在处理目录：" + dir);

	if (sizeof(file)) {
		for(i = 0,j = sizeof(file); i < j; i ++) {
		       	if (file[i][1] != -2 && sscanf(file[i][0], "%*s.c")
       				&& file[i][0][strlen(file[i][0])-1] == 'c'
				&& file[i][0][strlen(file[i][0])-2] == '.')
				check_one_file(me, dir + file[i][0]);
			else if (file[i][1] == -2 && recur)
				recur_check(me, dir + file[i][0], 1);
		}
	}
	
	return 1;
}
int check_one_file(object me,string file)
{
	object obj;
	int i;
	string text;

	reset_eval_cost();

	if (!(obj = find_object(file)))
		obj = load_object(file);

	if (!obj)
		return 0;

	text = read_file(file);
	
	for (i = 0; i < sizeof(base_room); i ++) {
		if (strsrch(text, base_room[i]) != -1 
		    && !obj->query("coor")) {
			write_file(COOR_LOG, file + "\n", 0);
			file_count ++;
			break;
		}
	}

	return 1;
}

int help(object me)
{
write(@HELP
指令格式: checkcoor [-d] [<路径名>]

检查指定目录下所有的文件的坐标情况，如果不指定
目录, 则使用当前目录。如果带参数-d，则连带处理
子目录。

HELP
);
return 1;
}
