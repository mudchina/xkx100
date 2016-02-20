// Room: /d/changcheng/fenghuotai2-1.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "烽火台");
	set("long", WHT @LONG
这里是烽火台的内部，这里不是很亮，四周乱糟糟的放着一些杂物，
但靠墙的兵器架上的兵器却擦的亮光闪闪，可见虽然生活很艰苦，但将
士们却没有忘记自己的责任。
LONG
NOR );
	set("exits", ([
		"up"       :__DIR__"fenghuotai2-2",
		"east"     :__DIR__"changcheng13",
		"northwest":__DIR__"changcheng14",
	]));
	set("no_clean_up", 0);
	set("coor/x", -10010);
	set("coor/y", 8000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}