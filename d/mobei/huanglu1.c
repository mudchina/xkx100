// Room: /d/mobei/huanglu1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这是条连接关内外的荒路，由于远离城镇，人烟稀少。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"south"     : "/d/changcheng/juyongguan",
		"northwest" : __DIR__"damo2",
	]));
	set("coor/x", -190);
	set("coor/y", 5100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
