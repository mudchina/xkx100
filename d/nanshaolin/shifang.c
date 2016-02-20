// Room: /d/nanshaolin/shifang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"石坊"NOR);
	set("long", @LONG
一个巨大的牌坊横架在两片山壁之间，牌坊正上方刻着六个斗大的
字：『闽中第一古刹』。字迹有些剥落，看上去年代颇为久远了。前方
是一片很大的广场，站满了前来进香的香客和一些江湖上的豪士。象征
着少林寺的山门殿，就矗立在广场的北侧。
LONG);

	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shanlu3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

