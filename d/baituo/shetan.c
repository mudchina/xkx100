// Room: /d/baituo/shetan.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", BLU"蛇潭"NOR);
	set("long", @LONG
一个阴深深的水潭，水面离地有丈高。你感觉到水里有东西在向你游
来。。。是蟒蛇！快跑(jumpup)吧！
LONG);
	set("objects", ([
		    __DIR__"npc/jumang" : 2
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20060);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object ob;       
	if (interactive(ob = this_player()))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_jumpup", "jumpup");
}

int do_jumpup(string arg)
{
	object me, ob;
	me = this_player();
	if(me->query("qi") < 100 ) 
		return notify_fail("你已经没有气力跳上去了。\n");

	if (objectp(present("ju mang", environment(me))))
	{
		if( me->query_dex() > 20 && me->query_dex() < 26)
		{
			message_vision( HIR"$N用力往上一纵，却又被巨蟒缠住了双足落了下来！\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			return 1;
		}
		if(me->query_dex() >= 26 && me->query_dex() < 32)
		{
			message_vision( HIY"$N用力往上一纵，虽差点又被巨蟒缠住了双足，但终于逃出了蛇潭！\n"NOR, me);
			me->receive_damage("qi", 150);
			me->receive_wound("qi", 50);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"从蛇潭之中爬上来，脚下一软，脸色苍白地坐倒在地。\n", ({ me }));
			return 1;
		}
		if(me->query_dex() >= 32)
		{
			message_vision(HIR"$N用力往上一纵，跳出了蛇潭。\n"NOR, me);
			me->receive_damage("qi", 50);
			me->receive_wound("qi", 10);
			me->move(__DIR__"yuanzi1");
			tell_room(environment(me),me->name()+"从蛇潭之中跳了上来，模样狼狈不堪。\n", ({ me }));
			return 1;
		}
		else
		{ 
			message_vision("$N使劲一跳，可是跳不上去。\n", me);
			return 1;
		}
	}
	else
	{ 
		message_vision("$N使劲一纵，跳出了蛇潭。\n", me);
		me->receive_damage("qi", 50);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"突然从蛇潭之中跳了出来，脸带恐惧之色。\n",({ me }));
		return 1;
	}
}

int greeting(object ob)
{
	object me = this_player();	
	if( (int)me->query_temp("baituo_climb") )
	{
		message_vision(HIR"$N从墙上跳了下来，正好落在了巨蟒身上！。\n"NOR,me);
		message_vision(HIR"$N还没回过神来，已经被巨蟒缠住了！\n"NOR,me);
		write(BLU"你被巨蟒缠住，越来越紧。。。\n你感到一切事物都开始慢慢远离你而去了。。。\n"NOR);
		me->delete_temp("baituo_climb");
		me->unconcious();
		return 1;
	}
	if((int)me->query_temp("baituo_climb1") )
	{
		message_vision(HIR"$N从墙上跳了下来，正好落在了巨蟒身旁！。\n"NOR,me);
		message_vision(HIR"$N猛力一跳，双脚却还是被巨蟒缠住！\n"NOR,me);
		write(BLU"你被巨蟒缠住，越来越紧。。。再不想法逃跑就死定了！\n"NOR);
		me->receive_damage("qi", 500);
		me->receive_wound("qi", 200);
		me->delete_temp("baituo_climb1");
		return 1;
	}
	if( (int)me->query_temp("baituo_climb2") )
	{
		message_vision(HIR"$N刚刚飞纵过来，就发现了蛇潭里有巨蟒！。\n"NOR,me);
		write(BLU"你看见巨蟒向你卷了过来，快走！\n"NOR);
		message_vision( HIY"$N身在半空双臂一挥，身体借力又直飞出去，跳出了蛇潭！\n"NOR, me);
		me->add("neili", -100);
		me->move(__DIR__"yuanzi1");
		tell_room(environment(me),me->name()+"从蛇潭之中飞跃上来，脸上带着惊讶之色。\n",({ me }));
		me->delete_temp("baituo_climb2");
		return 1;
	}      
}
