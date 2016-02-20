// Room: /d/baituo/midaoout.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"秘道"NOR);
	set("long", @LONG
这条阴暗的秘道在山腹中曲折延伸，不知通往何处。前面的道路越
来越暗，你快要看不见东西了。这里空气污浊，还夹杂着一股刺鼻的味
道，你一走过来便觉得头脑发晕，象是中毒了。
LONG);		
	set("exits", ([
		"west"  : __FILE__,
		"east"  : __DIR__"midao8",
		"north" : __DIR__"midao7",
		"south" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -49910);
	set("coor/y", 20070);
	set("coor/z", -20);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <15 && me->query_con() < 35)
	{
		tell_object(me, HIB"你忽然感到呼吸一紧，原来是这里的空气污浊、流通不畅。\n" NOR );	
		tell_room(environment(me),me->name()+"突然脸色变得极为难看，并深深地吸了口气。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
	add_action("do_use", "use");
	add_action("do_tui", "tui");
}

int do_use(string arg)
{
	object me = this_player();
	if( !arg || arg=="" ) return 0;
	if (!present("fire", me)) return 0;
	if( arg=="fire" )
	{
		write( "你点燃了火折，发现前面石壁上有一洞口，但被巨石堵住了，\n不知能不能推(tui)开它。\n");
		me->set_temp("marks/推", 1);
		return 1;
	}
}

int do_tui(string arg)
{
	object me = this_player();
	if (arg == "stone" || arg == "jushi" )
	{
		if (me->query_temp("marks/推") )
		{
			if(me->query_skill_mapped("force") != "hamagong" )
			{
				me->add("max_neili", -1);
				message_vision(HIR "$N运气猛力向巨石一击，结果不但没推开它，反而震伤了自己。\n" NOR, me);
				me->unconcious();
				return 1;
			}
			else
			{
				message_vision("$N出掌抵住巨石，猛地一推将巨石推开一条缝钻了出去。\n", me);
				me->move(__DIR__"hswz");
				message("vision", me->name() + "从乱石堆里钻了出来。\n",environment(me), ({me}) );
				me->set_temp("marks/推", 0);
				return 1;
			}
		}
	}
	else
	{
		write("你想推什么？\n");
		return 1;
	}
}
