// npccmd.c
//
inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string cname,ccmds;
        object ob;

        cname = me->query_temp("snoopee");
        if( cname == 0 ) return notify_fail("你没有监听任何人。\n");
        ob = find_player(cname);
        if( !ob )
                ob = find_living(cname);
        if( !ob )
                return notify_fail("找不到你所监听的人。\n");
        if( !arg )
        return notify_fail(sprintf("你要让%s作什麽事？\n",ob->name()));
        if( arg == "e" ) arg = "east";
        if( arg == "w" ) arg = "west";
        if( arg == "s" ) arg = "south";
        if( arg == "n" ) arg = "north";
        if( arg == "u" ) arg = "up";
        if( arg == "d" ) arg = "down";
        if( arg == "se" ) arg = "southeast";
        if( arg == "sw" ) arg = "southwest";
        if( arg == "ne" ) arg = "northeast";
        if( arg == "nw" ) arg = "northwest";
        if( arg == "l" ) arg = "look";

        return ob->force_me(arg);
}

int help(object me)
{
   write( @HELP
指令格式: % <commands> 给你所监听的人发命令.
HELP
   );
   return 1;
}
