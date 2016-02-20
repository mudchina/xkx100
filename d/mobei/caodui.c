// Room: /d/mobei/caodui
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "大草堆");
	set ("long", @LONG
蒙古人一过炎夏，便割草堆积，冬日饲养牲口，烧火取暖，全凭干
草，是以草堆往往比住人的蒙古包还大。一边是个简陋的小茅草屋。
LONG);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"enter"   : __DIR__"maowu",
		"west"    : __DIR__"byriver",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
