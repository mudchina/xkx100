// Room: /d/lingxiao/car.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
int do_take(string arg);
void create()
{
	set("short","冰车");
	set("long",@LONG
这里是凌霄城的冰车（bing che）下山之处，此冰车是凌霄城为了
能直达扬州，所特制而成，能从这雪山之巅飞速滑下，是从雪山去往扬
州的交通工具。你可以乘坐（take）它滑往扬州。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"iceroad3",
	])); 
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("item_desc", ([
		"bing che" : "一台上好红杉木所制的冰车，供凌霄弟子下山之用。\n"
	]) );
	set("coor/x", -31010);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
}
void init()
{
	add_action("do_take", "take");
}
int do_take(string arg)
{
	object me=this_player();

	if( !arg || arg != "bing che" )
	{
		return notify_fail("你要坐什么？\n");
	}
	if (me->query("family/family_name") != "凌霄城")
		return notify_fail("凌霄弟子道：你又不是凌霄城的，走开。\n");

	message_vision(HIW"$N稳稳当当坐上冰车，向凌霄弟子打个手势。\n那弟子点了点头，将开关一扳，冰车就如离弦之箭，向下飞射而出。\n"NOR, me);
	message_vision(HIW"万里雪山在$N身边逝过，如白驹之逝，飞翼之行。$N心神大快，忍不住纵声长啸。\n"NOR, me);
	me->move("/d/city/shilijie4");
	return 1;
}

