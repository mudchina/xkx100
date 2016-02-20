// /d/meizhuang/midao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
地道一路向下倾斜，地势不断的向下倾斜，只怕已深入地底百丈有
余，现在大概已经在西湖底下了。墙壁上点着一盏油灯，发出淡黄色光
芒。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"northup"   : __DIR__"midao2",
		"southdown" : __DIR__"midao4",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1440);
	set("coor/z", -100);
	setup();
	replace_program(ROOM);
}
