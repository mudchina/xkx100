// /d/meizhuang/midao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
这是一条昏暗潮湿的地道，地道大概两丈长，尽头处是一扇石门。
墙壁上点着一盏油灯，发出淡黄色光芒。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"up"        : __DIR__"neishi",
		"southdown" : __DIR__"shimen",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3510);
	set("coor/y", -1410);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
