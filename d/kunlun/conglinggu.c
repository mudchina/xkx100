// Room: /d/kunlun/conglinggu.c 葱岭谷
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "葱岭谷");
	set("long",@long
你的眼前突然为之一亮，只见一条象被一刀劈开的峡谷岩石间，高
山的雪水泻落到千丈以下的山涧里去，溅起的密密的飞沫激起一种惊心
动魄的震憾。就在这深山野谷的溪流边，却长满了各种各样的花草树木，
春天繁花开遍峡谷秋天果实压满山腰，人迹罕至，正是鸟兽们(bird)的
乐园。
long );
	set("item_desc",([
		"bird" : "各种珍奇异鸟,你不禁拿起了地上的石子,向他们投(tou)去。\n",
	]));
	set("exits",([
		"out" : __DIR__"shanlin"+(random(5)+1),
	]));
	set("objects", ([
		VEGETABLE_DIR"huangqi" : 1,
		VEGETABLE_DIR"dongchongcao" : 2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
}

int init()
{
	add_action("do_tou","tou");
}

int do_tou(string arg)
{
	object me = this_player();
	if ( !living(this_player()) || arg != "bird" )
		return notify_fail("你用石头投掷谁？\n");
	if ((int)me->query_skill("throwing", 1) > 100)
		return notify_fail("你的暗器功夫已相当高了，对这种小儿科毫无兴趣。\n");
	if ( (int)me->query("qi")<30)
	{
		me->receive_damage("qi", 10);
		write("你的胳膊已经酸了,还是先休息一会吧！\n");
		return 1;
	}
	me->receive_damage("qi", random(25));
	message_vision("$N正在用石头打鸟。\n", me);
	write("你专心致志的向鸟群投掷石头，感觉基本暗器又进了一步。\n");
	me->improve_skill("throwing", me->query_int());
	return 1;
} 
