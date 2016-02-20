// yiru@hero
inherit F_CLEAN_UP;

#define SYNTAX  "syntax :coor x,y,z\n"



int recur_do(object room, int x, int y, int z);
int continue_do(object room);

int main(object me, string arg)
{
        int x,y,z;
        int single;

        object env = environment(me);

        if (!me->query("env/yesiknow"))
                return notify_fail("这个指令已经被废除了！\n");

        if (!arg) {
                if (env->query("coor")) {
                        continue_do(env);
                        return 1;
                } else
                        return notify_fail("用法不对，请参考帮助。\n");
        }

        if (arg == "-d") {
                write("房间 " + base_name(env) + " 已非边界。\n");
                env->delete("border");
                return 1;
        }

        if (arg == "-b"){
                env->set("border", 1);
                write("房间 " + base_name(env) + " 已设为边界。\n");
                return 1;
        }

        if (sscanf(arg, "%d,%d,%d", x, y, z) != 3)
                return notify_fail("用法不对，请参考帮助。\n");

        seteuid(getuid());

        if (env->query("coor")) {
                env->set("coor/x", x);
                env->set("coor/y", y);
                env->set("coor/z", z);
                write("房间 " + base_name(env) + " 坐标重新设定成功。\n");
        } else
                recur_do(environment(me), x, y, z);

        return 1;
}

int recur_do(object room, int x, int y, int z)
{
        mapping exits;
        string *directions;
        string dir;
        object nextroom;
        int j;

        reset_eval_cost();

	if (room->query("coor"))
		return 1;

        room->set("coor/x", x);
        room->set("coor/y", y);
        room->set("coor/z", z);
        write("房间 " + base_name(room) + " 坐标设定成功。\n");

        if (room->query("border"))
                return 1;

        exits = room->query("exits");
        if (!mapp(exits) || !sizeof(exits))
                return 1;

        directions = keys(exits);
        for (j = 0; j < sizeof(directions); j ++) {
                x = (int)room->query("coor/x");
                y = (int)room->query("coor/y");
                z = (int)room->query("coor/z");

                dir = directions[j];
                if(!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);

                switch (dir) {
                        case "east"     : x+=10;recur_do(nextroom,x,y,z);break;
                        case "west"     : x-=10;recur_do(nextroom,x,y,z);break;
                        case "south"    : y-=10;recur_do(nextroom,x,y,z);break;
                        case "north"    : y+=10;recur_do(nextroom,x,y,z);break;
                        case "up"       : z+=10;recur_do(nextroom,x,y,z);break;
                        case "down"     : z-=10;recur_do(nextroom,x,y,z);break;
                        case "eastup"   : x+=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "westup"   : x-=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "southup"  : y-=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "northup"  : y+=10;z+=10;recur_do(nextroom,x,y,z);break;
                        case "eastdown" : x+=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "westdown" : x-=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "southdown": y-=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "northdown": y+=10;z-=10;recur_do(nextroom,x,y,z);break;
                        case "southeast": y-=10;x+=10;recur_do(nextroom,x,y,z);break;
                        case "southwest": y-=10;x-=10;recur_do(nextroom,x,y,z);break;
                        case "northeast": y+=10;x+=10;recur_do(nextroom,x,y,z);break;
                        case "northwest": y+=10;x-=10;recur_do(nextroom,x,y,z);break;
                }
        }
        return 1;
}

int continue_do(object room)
{
        mapping exits;
        string *directions;
        string dir;
        object nextroom;
        int x, y, z, j, coored = 0;

        reset_eval_cost();

	if (room->query("coor"))
		coored = 1;
        if (room->query("border"))
                return 1;

        exits = room->query("exits");
        if (!mapp(exits) || !sizeof(exits))
                return 1;

        directions = keys(exits);
        for (j = 0; j < sizeof(directions); j ++) {
                x = (int)room->query("coor/x");
                y = (int)room->query("coor/y");
                z = (int)room->query("coor/z");

                dir = directions[j];
                if(!objectp(nextroom=find_object(exits[dir])))
                        nextroom=load_object(exits[dir]);

                switch (dir) {
                        case "east"     : x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "west"     : x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "south"    : y-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "north"    : y+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "up"       : z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "down"     : z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "eastup"   : x+=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "westup"   : x-=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southup"  : y-=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northup"  : y+=10;z+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "eastdown" : x+=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "westdown" : x-=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southdown": y-=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northdown": y+=10;z-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southeast": y-=10;x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "southwest": y-=10;x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northeast": y+=10;x+=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                        case "northwest": y+=10;x-=10;coored?recur_do(nextroom,x,y,z):continue_do(nextroom);break;
                }
        }
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : hcoor <参数> x,y,z

用法：
        hcoor           从当前房间（已定位）开始递归定位坐标。
        hcoor x,y,z     若当前房间已定位，则重新定位该房间，
			否则从当前房间开始递归定位坐标。
        hcoor -b        设定当前房间为边界。
        hcoor -d        设定当前房间为非边界。
HELP
);
    return 1;
}
