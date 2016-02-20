// Last Modified by winder on Apr. 25 2001

inherit F_CLEAN_UP;
 
#include <ansi.h>
 
int rm_dir(string dir);
int help(object me);

int main(object me, string arg)
{
	string file;
	string dir;
	int rm_dir;
	int count;
 
	if (me != this_player(1)) return 0;
	seteuid(geteuid(me));
 
	if (! arg)
	{
		help(me);
		return 1;
	}

	if (sscanf(arg, "-R %s", dir) == 1)
	{
		rm_dir = 1;
	} else
	{
		dir = arg;
		rm_dir = 0;
	}

	file = resolve_path(me->query("cwd"), dir);
 
	switch (file_size(file))
	{
	case -1:
		write("没有这个文件。\n");
		return 1;
	case -2:
		if (rm_dir)
		{
			write(HIR "删除目录中，请稍候..." NOR),

			count = rm_dir(file);
			if (count)
				write(HIY "总共有" + count + "个文件被成功删除。\n" NOR);
			return 1;
		}

		if (rmdir(file))
			write("成功的删除了目录(" + file + ").\n");
		else
			write("你没有删除该目录的权限或者试图删除一个"
			      "非空的目录。\n");
		return 1;
		
	default:
		if (rm(file))
			write("成功的删除了文件(" + file + ").\n");
		else
			write("你没有删除它的权限。\n");
		return 1;
	}
}
 
int rm_dir(string dir)
{
	mixed *file;
	int count;
	int i;
/*
	if (! is_root(previous_object()))
		return 0;
*/
	count = 0;
	if (dir[strlen(dir) - 1] != '/') dir += "/";
	file = get_dir(dir, -1);

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] != -2)
			if (rm(dir + file[i][0]))
				count++;
	}

	i = sizeof(file);
	while (i--)
	{
		reset_eval_cost();
		if (file[i][1] == -2)
			count += rm_dir(dir + file[i][0]);
	}

	write (HIC "删除目录(" + dir + ")。\n" NOR);
	rmdir(dir);
	return count;
}

int help(object me)
{
  write(@HELP
指令格式 : rm [-R] 档案名
 
此指令可让你删除某个档案或目录。如果使用了-R参数，可以删除非空的目
录，使用该参数务必要小心，以免删除错路径。
HELP
    );
    return 1;
}

