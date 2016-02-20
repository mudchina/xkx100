// flyto.c

inherit F_CLEAN_UP;

#include <ansi.h>
#include <command.h>


int main(object me, string arg)
{
        string home;
        int goto_inventory = 0;
        object obj;
        string msg;
        if( !arg ) return notify_fail("你要往哪儿飞？\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        if( !arg ) return notify_fail("你要飞到哪儿去？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("这个物件没有环境可以 flyto。\n");
         tell_object(me,"咦，怎么还不起飞呢？……\n");
         tell_object(me,"呵呵呵呵，飞了飞了！小小巫师飞呀飞……！\n");
         me->move(obj);

        tell_object(me,"到了？到了！降落喽！！！\n");
        return 1;
}

int help(object me)
{write(@HELP
指令格式 : flyto [-i] <目标>
HELP);
    return 1;
}
