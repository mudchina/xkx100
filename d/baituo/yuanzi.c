// Room: /d/baituo/yuanzi.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小花园");
	set("long", @LONG
这是个不大的花园，中间一堆假山，一条小溪。旁边种满了各类花
草，芳香宜人。北面有一道锁着的铁门(tiemen)，可以通往另一个院子。
LONG);
	set("exits", ([
		"west" : __DIR__"tuitang",
	]));
	set("item_desc", ([		
		"tiemen" : "\n这道铁门极其沉重，看来没有几百斤臂力推它不动。真是奇怪为\n何会有如此铁门在此，就连一般人都可以翻越(climb)旁边的矮墙。\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	add_action("do_fan", "fan");
	add_action("do_fan", "pa");
	add_action("do_fan", "climb");
	add_action("do_push", "push");
	add_action("do_push", "tui");
	add_action("do_push", "strike");
	add_action("do_wen", "wen");
	add_action("do_wen", "smell");
}

int do_fan(string arg)
{
	int dex;
	object me;	
	dex = this_player()->query_dex();
	me = this_player();	
	if( (int)me->query("hamagong") ) 
		return notify_fail("你正想翻过墙去，突然有了一股想推开铁门的冲动。\n");
	if (dex < 18 )
		return notify_fail("这矮墙虽矮，你却怎么也翻不过去。\n");
	if (dex > 17 && dex < 25)
	{
		message_vision("$N双手在矮墙上一按，一翻身便纵了过去。\n", me);
		me->set_temp("baituo_climb", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 24 && dex < 36)
	{
		message_vision("$N运功提气轻轻一纵，便跃了过去。\n", me);
		me->set_temp("baituo_climb1", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 35)
	{
		message_vision("$N脚尖轻轻一点，高高跃起，飘了进去。\n", me);
		me->set_temp("baituo_climb2", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}	
}

int do_push(string arg)
{
	int str;
	object me;
	str = this_player()->query_str();
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "tiemen" )
	{
		if( (int)me->query_skill("hamagong", 1))
		{
			message_vision("$N蹲下身子，双掌平伸推向铁门。\n", me);
			message_vision("铁门突然打开，$N一没留神滚了进去。铁门却又合上了。\n", me);
			me->add("neili", -100);
			me->receive_damage("qi", 50);
			me->move(__DIR__"yuanzi1");
			return 1;
		}
		if (str < 21 )
			return notify_fail("你使出了吃奶的力气，可就是推不动这铁门。\n");
		if (str > 20 && str < 30)
		{
			message_vision("$N使出全身力气推向铁门，可铁门只轻轻动了一下。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 29 && str < 38)
		{
			message_vision("$N运功提气猛地推向铁门，铁门发出了轰轰的震动声，看来马上就可以推开了。\n可这时$N的力气刚好使完，只得作罢。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 37)
		{
			message_vision("$N内劲运转，双掌平伸推向铁门。\n", me);
			message_vision("铁门突然打开，$N一没留神滚了进去。铁门却又合上了。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			me->move(__DIR__"yuanzi1");
			return 1;
		} 
	}
	return 1;	
}

int do_wen(string arg)
{
	int con;
	con = this_player()->query_con();

	if ( con > 29 && con < 37)
		write( "你轻轻吸了吸气，突然感觉到花香中隐隐带有股腥味。但闻不出是从哪儿来的。\n");
	if ( con > 36 )
		write( "你轻轻吸了吸气，突然感觉到花香中隐隐带有股腥味。好象是从铁门那边的院子飘来的。\n");
	if ( con < 30 )
		write("你轻轻吸了吸气，全是芬芳的花香，你都快醉了。\n");
	return 1;	
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_climb");
	me->delete_temp("baituo_climb1");
	me->delete_temp("baituo_climb2");
	return ::valid_leave(me, dir);
}
