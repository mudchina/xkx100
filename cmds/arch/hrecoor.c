// /cmds/arch/hrecoor.c

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int recur_do(object room, int depth);
int continue_do(object room, int depth);

int main(object me, string arg)
{
	object env;

	env = environment(me);

        if (!me->query("env/yesiknow"))
        	return notify_fail("这个指令已经被废除了！\n");
	
	if (!env->query("coor"))
		return notify_fail("您所在的房间尚未定位坐标，请先用hcoor指令。\n");

	if (arg == "here") {
		recur_do(env, -1);
		return 1;
	}

	if (env->query("already_coordinated"))
		continue_do(env, 0);
	else
		recur_do(env, 0);

	return 1;
}

int recur_do(object room, int depth)
{
	mapping exits;
	string *directions;
	string dir;
	string file, *lines;
	object nextroom;
	int x, y, z, j;
	int flag = 0;

	if (!room->query("coor"))
		return 1;

	if ( room->query("already_coordinated"))
		return 1;

	if (depth > 20)
	        return 1;

	seteuid(getuid());

	reset_eval_cost();
	x = (int)room->query("coor/x");
	y = (int)room->query("coor/y");
	z = (int)room->query("coor/z");
	file = read_file(base_name(room)+".c");
	file = replace_string(file, sprintf("set(\"coor/x\", %d);\n\t", x), "");
	file = replace_string(file, sprintf("set(\"coor/y\", %d);\n\t", x), "");
	file = replace_string(file, sprintf("set(\"coor/y\", %d);\n\t", x), "");
	file = replace_string(file, "setup()",
	sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", x, y, z));

	if (write_file(base_name(room) + ".c", file, 1)) {
        	write("房间 " + base_name(room) + " 已成功写入文件。\n");
	        room->set("already_coordinated", 1);
	}

	if (room->query("border"))
		return 1;

	if (depth == -1)
		return 1;

	exits = room->query("exits");
	if (!mapp(exits) || !sizeof(exits))
		return 1;

	directions = keys(exits);
	for (j=0; j<sizeof(directions); j++) {
		dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);
		recur_do(nextroom, depth + 1);
	}

	return 1;
}

int continue_do(object room, int depth)
{
	mapping exits;
	string *directions;
	string dir;
	string file, *lines;
	object nextroom;
	int x, y, z, j;
	int recoored = 0;

	if (!room->query("coor"))
		return 1;

	if (!room->query("border"))
		return 0;

	if (depth > 20)
	        return 1;

	seteuid(getuid());
	if (room->query("already_coordinated"))
		recoored = 1;

	exits = room->query("exits");
	if (!mapp(exits) || !sizeof(exits))
		return 1;

	directions = keys(exits);
	for (j=0; j<sizeof(directions); j++) {
		dir = directions[j];
                if (!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);
		recoored?continue_do(nextroom, depth + 1):recur_do(room, 0);
	}

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : hrecoor [here]

用法：
	用hcoor设定好一个区域内的所有房间后，在该区域任意一点都可以使用
	hrecoor把一批房间坐标写入文件，反复使用该指令，直至所有房间都被
	写入。若带here参数，则只处理当前房间。
HELP
);
    return 1;
}


