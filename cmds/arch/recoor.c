// /cmds/arch/recoor.c 

// Created by Constant Jan 8 2001

inherit F_CLEAN_UP;

int file_count;

int non_recur_do(object room, string prefix);

int main(object me, string arg)
{
        int x, y, z, i;
        int single = 0, all = 0;
        object env = environment(me);
        string prefix, file, *file_name;

        if (!me->query("env/yesiknow"))
                return notify_fail("危险指令，慎用！慎用！\n");

	set_eval_limit(2100000000);
	reset_eval_cost();

	if (arg && arg != "here" && arg != "-a")
		return notify_fail("用法不对，请参考帮助。\n");

	if (env->query("recoored") && arg!= "here")
		return notify_fail("您所在的房间坐标已经写入过了。\n");

	if (!env->query("coor"))
        	return notify_fail("您所在的房间尚未定位坐标，请先用hcoor指令。\n");

	if (arg == "-a")
		all = 1;

        if (arg == "here")
               	single = 1;

        seteuid(getuid());

	file_count = 0;
	file_name = explode(base_name(env), "/");
	prefix = "";
	
	if (!all) {
       		for (i = 0; i < sizeof(file_name)-1; i ++)
        		prefix += file_name[i] + "/";
        }

        if (single) {
		x = (int)env->query("coor/x");
		y = (int)env->query("coor/y");
		z = (int)env->query("coor/z");
		file = read_file(base_name(env) + ".c");
		file = replace_string(file, "setup()",
			sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
				x, y, z));
		write_file(base_name(env) + ".c", file, 1);
                file_count ++;
        	write("房间 " + base_name(env) + " 坐标已成功写入文件。\n");
        } else
                non_recur_do(env, prefix);

	write("共写入 " + sprintf("%d", file_count) + " 个文件。\n");
        return 1;
}

int non_recur_do(object room, string prefix)
{
	mapping roomlist = ([]);
        mapping exits;
        string *directions;
        string dir, file;
        object curr_room, next_room;
        int x, y, z, i;

	x = (int)room->query("coor/x");
	y = (int)room->query("coor/y");
	z = (int)room->query("coor/z");
	file = read_file(base_name(room) + ".c");
	file = replace_string(file, "setup()",
		sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
			x, y, z));
	write_file(base_name(room), file, 1);
	file_count ++;
        write("房间 " + base_name(room) + " 坐标已成功写入文件。\n");
        room->set("recoored", 1);
        roomlist += ([base_name(room) : room]);

	while (sizeof(roomlist)) {

        	reset_eval_cost();

		curr_room = values(roomlist)[0];
		map_delete(roomlist, keys(roomlist)[0]);

	        exits = curr_room->query("exits");
	        if (!mapp(exits) || !sizeof(exits))
        	        return 1;

	        directions = keys(exits);

	        for (i = 0; i < sizeof(directions); i ++) {

	        	reset_eval_cost();
	        	
                	dir = directions[i];
                	if(!objectp(next_room=find_object(exits[dir])))
                        	next_room=load_object(exits[dir]);

			reset_eval_cost();
			if (next_room->query("coor")
			    && !next_room->query("recoored")
			    && !roomlist[base_name(next_room)]
			    && (strsrch(base_name(next_room), prefix) != -1
			    	|| prefix == "" )) {
				x = (int)next_room->query("coor/x");
				y = (int)next_room->query("coor/y");
				z = (int)next_room->query("coor/z");
				file = read_file(base_name(next_room) + ".c");
				file = replace_string(file, "setup()",
					sprintf("set(\"coor/x\", %d);\n\tset(\"coor/y\", %d);\n\tset(\"coor/z\", %d);\n\tsetup()", 
						x, y, z));
				write_file(base_name(next_room) + ".c", file, 1);
				file_count ++;
        			write("房间 " + base_name(next_room) + " 坐标已成功写入文件。\n");
        			next_room->set("recoored", 1);
       				roomlist += ([base_name(next_room) : next_room]);
       			}
		}
        }

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : recoor [-a | here]

用法：
	recoor		将当前房间所在目录下所有房间坐标
			都写入文件，当前房间须未曾写入过。
        recoor -a	同上，但无目录限制。
	recoor here	强制将当前房间的坐标写入文件。
	
HELP
);
    return 1;
}
