// Room: /d/baituo/shidui.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "乱石堆");
	set("long", @LONG
这里四周所围全是巨石，地上铺满了凌乱的碎石子，象是被人击打
巨石所打下来的碎块。正中一块平滑的青石板上蹲着一只雪白的蛤蟆。
LONG);	
	set("objects", ([
		__DIR__"npc/chanchu" : 1,
	]));
	set("item_desc", ([
		"stone": "\n这些巨石都有凹面，看得出是被人拿来练掌力用的。\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49910);
	set("coor/y", 20090);
	set("coor/z", 40);
	setup(); 
}

void init()
{
	object me = this_player();	
	if(me->query("id") != "xuanbing chanchu") 
	if(me->query_skill("xidu-poison",1) < 50) 
	{
		message_vision(HIW"玄冰蟾蜍突然纵起，对着$N一口毒气喷出！\n"NOR,this_player()); 
		tell_object(me, HIB"你感到脑中一阵旋晕，立时昏了过去。\n" NOR );
		me->unconcious();
		me->move(__DIR__"yuanzi5");
		tell_room(environment(me),me->name()+"突然从巨石之上直落下来，‘叭’的一声摔在地上！\n", ({ me }));
		me->add("max_neili", -1);
	}
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_strike", "strike");
}

int do_climb(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		message_vision("$N手脚并用，爬上了巨石去。\n", me);
		message_vision("$N翻身一纵，已经跳了出去。\n", me);
		me->move(__DIR__"yuanzi5");
		message("vision", me->name() + "从里面跳了出来。\n",environment(me), ({me}) );
		return 1;
	}
}

int do_strike(string arg)
{
	object me = this_player();
	int improve, cost, lvl, exp;

	lvl = me->query_skill("strike",1);
	exp = me->query("combat_exp");
	improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
	if( !arg || arg=="" ) return 0;
	if (arg == "stone" )
	{
		if(!me->query_skill("hamagong", 1))
			return notify_fail("你用手指推了推巨石，脸上露出一丝难堪的神色。\n");
		if(me->query_skill("hamagong", 1) > 100)
			return notify_fail("你一掌向巨石推去，只听轰的一声，巨石被你掌力震成两半！\n");
		cost = 300 / (int)me->query("int");
		cost = 300 / (int)me->query("int");

		if((int)me->query("qi") < cost || (int)me->query("jing") < cost)
		{
			message_vision("$N用力过猛, 一不留神劲力反弹，震得$N晕了过去。\n",me);
			me->unconcious();
			return 1;
		} 
		message_vision("$N默诵蛤蟆功口诀，运力于双掌之上，一掌掌向巨石推去。\n"NOR,this_player());
		if ( lvl < 100 && lvl*lvl*lvl/10 < exp)
			me->improve_skill("strike", improve/4); 
		me->improve_skill("hamagong", improve);
		me->receive_damage("jing", cost);
		me->receive_damage("qi", cost);			
		return 1;
	}
}

