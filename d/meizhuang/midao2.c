// /d/meizhuang/midao2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道一路向下倾斜，地势不断的向下倾斜，墙壁上点着一盏油灯，
发出淡黄色光芒。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"shimen",
		"southdown" : __DIR__"midao3",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1430);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
