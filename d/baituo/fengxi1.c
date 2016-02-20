// Room: /d/baituo/fengxi1.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "缝隙");
	set("long", @LONG
这里是石块与石块之间的夹缝，光线昏暗。你明显感觉到四周的沙沙
声是各种毒虫爬行的声音，一股股腥味中也夹杂着一些刺鼻的气息。你发
现前面有一石块(shikuai) 隐隐发出淡淡的光芒。
LONG);
	set("objects", ([
		__DIR__"npc/fushe" : 2
	]));
	set("exits", ([
		"south" : __DIR__"fengxi",
		"west"  : __DIR__"fengxi2",
		"out"   : __DIR__"yuanzi3",
	]));
	set("item_desc", ([		    
		"shikuai":RED"\n这块石头呈红汞色，散发着阵阵热气，石块上凹陷进去的部分是个左手手掌形。\n"NOR,
	]));
	set("coor/x", -49900);
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
	if( !me->query_temp("baituo_stone") ) return 0;
	if( (int)me->query_temp("baituo_stone1") ) 
		return notify_fail("你已经推动过了石块。\n");
	if (arg == "shikuai" )
	{
		message_vision("$N深深吸了口气，伸出左手按住石块上的手印，缓缓向下推去。\n", me);	    
		me->set_temp("baituo_stone1", 1);
		message_vision("$N将石块按下寸许，隐隐约约听到地下传来一阵轰隆声。\n", me);
		me->start_busy(5);      
		call_out("poisoned", 5, me);
		return 1;
	}     
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 80 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, RED"你感到石块上的炎热之气顺着手臂慢慢传了上来。\n\n" NOR );
		message_vision("$N突然身子一颤，好象是中了热毒！\n", me);
		me->apply_condition("hot_poison", 50);
		me->delete_temp("baituo_stone");
		return 1;
	}   
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 80)
	{
		tell_object(me, RED"忽然一股炎热之气顺着手臂从石块上慢慢传了上来。\n\n" NOR );
		tell_object(me, HIW"你连忙运功调气，将侵入手臂的炎热之气尽数逼了出去。\n" NOR );
		me->delete_temp("baituo_stone");
		return 1;
	}	       
}
