// Room: /d/jueqinggu/qiaobi.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "峭壁");
	set("long", @LONG
这里是一块较平坦的岩石，只能一两个人容身。岩壁上模模糊糊有
几行字(zi)，似乎是利器划刻上去的，大概是因为时间久远，只能勉强
认得。下望是雾气弥漫的深谷谷底。
LONG
	);
	set("item_desc", ([
		"zi" : HIW "十六年后，在此相会，夫妻情深，勿失信约。
小龙女书嘱夫君杨郎，珍重万千，务求相聚。\n"NOR,]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 50);
	setup();
 
}
void init()
{
	add_action("do_pa", "pa");
	add_action("do_jump", "jump");
}
int do_pa(string arg)
{
	object me = this_player();

	if( !arg || arg == "" || (arg != "gudi" && arg != "谷底") ) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20)
		return notify_fail("你身上负重太多，爬不下去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
	return notify_fail("以你目前的轻功修为，很难爬下去。\n"); 
	message_vision("$N扒住岩石，小心的爬了下去。\n", me);
	me->move(__DIR__"gudi1");
	tell_room(environment(me), me->name() + "从上面爬了下来。\n", ({ me }));
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "duanchang ya" && arg != "断肠崖" && arg != "ya") return 0;
	if ( !arg ) return 0;
 
	
	if (!living(me)) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20) 
	return notify_fail("你身上负重太多，无法跳过去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
		return notify_fail("以你目前的轻功修为，无法跳过去。\n"); 
	message_vision("$N纵身向上面的断肠崖跳过去。\n", me);
	me->move(__DIR__"duanchangya");
	tell_room(environment(me), me->name() + "从峭壁跳了过来。\n", ({ me }));
	return 1;
}
