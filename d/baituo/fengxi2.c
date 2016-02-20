// Room: /d/baituo/fengxi2.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "缝隙");
	set("long", @LONG
这里是石块与石块之间的夹缝，光线昏暗。你明显感觉到四周的沙
沙声是各种毒虫爬行的声音，一股股腥味中也夹杂着一些刺鼻的气息。
你发现前面有一石块(shikuai) 隐隐发出淡淡的光芒。
LONG);
	set("objects", ([
		__DIR__"npc/yanjing1" : 1,
		__DIR__"npc/hama" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"fengxi1",
		"out"  : __DIR__"yuanzi4",
	]));
	set("item_desc", ([		    
		"shikuai":HIW"\n这块石头呈乳白色，散发着阵阵暖气，石面有一道五彩色的细线，\n石块上凹陷进去的是个左右两个手掌的手掌形。\n"NOR,
	]));
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 20);
	setup(); 
}

void init()
{
	add_action("do_push", "tui");
	add_action("do_push", "push");	
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( !me->query_temp("baituo_stone1") ) return 0;
	if( (int)me->query_temp("baituo_stone2") ) 
		return notify_fail("你已经推动过了石块。\n");
	if (arg == "shikuai" )
	{
		message_vision("$N深深吸了口气，伸出双手按住石块上的手印，缓缓向下推去。\n", me);	   
		me->set_temp("baituo_stone2", 1);
		message_vision("$N将石块按下寸许，隐隐约约听到地下传来一阵轰隆声。\n", me);	    
		me->start_busy(5);	
		call_out("poisoned", 5, me);
		return 1;
	}	
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 120 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, MAG"你感到手心一凉，那道五彩细线已经附在你的手心上。\n" NOR );
		message_vision("$N突然身子一颤，好象是中了毒！\n", me);
		me->apply_condition("bt_poison", 50);
		me->delete_temp("baituo_stone1");
		return 1;
	}   
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 120)
	{
		tell_object(me, MAG"忽然你的手心一凉，那道五彩细线已经附在你的手上。\n" NOR );
		tell_object(me, HIW"你连忙运功调气，将手心的五彩细线逼出了大半。\n" NOR );
		me->apply_condition("snake_poison", 30);
		me->delete_temp("baituo_stone1");
		return 1;
	}
}
