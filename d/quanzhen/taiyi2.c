// taiyi2.c
// Java Oct.10 1998
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "太乙池");
        set("long", @LONG
你身在湖水里，只觉得湖水冰凉透骨。但见四周高峰环列，池面
碧波荡漾，山光水影，风景贻人。这里原来是太乙池的东岸，太累的
话，你可以爬(climb) 上岸。远远望去，西边的山峰之间似乎有一个
大洞。想不想游(swim)过去看？
LONG
        );
        set("outdoors", "zhongnan");
	set("coor/x", -3190);
	set("coor/y", 180);
	set("coor/z", 40);
	setup();
}
void init()
{
        add_action("do_climb", "climb");
        add_action("do_swim", "swim");
}
int do_climb(string arg)
{
        object me = this_player(); 
        int c_exp;
        c_exp = me->query("combat_exp");
        if( !arg || arg != "up")
        {
                write("那个方向没法爬。\n");
                return 1;
        }

        message_vision("$N在太乙池中往岸上爬了上去。\n", me);
        me->move("/d/quanzhen/taiyi1");
        message_vision("$N从太乙池中爬了上去。\n", me);
        return 1;
}
int do_swim()
{
        int c_exp,c_skill;
        object me = this_player();

        c_exp=me->query("combat_exp");
        c_skill=me->query_skill("jinyan-gong",1);
	if ( me->query("qi") < 10 )
		me->unconcious();
	else
	{
        	me->receive_damage("qi",10);
        	if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill < 51))
			me->improve_skill("jinyan-gong", (int)me->query_skill("jinyan-gong", 1));
	        message_vision("$N在太乙池中划了划水，用力游了起来。\n", me);
	}
        return 1;
}
