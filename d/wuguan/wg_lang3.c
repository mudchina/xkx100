// Last Modified by Sir on 9/17/2001
// wg_lang3.c

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，一直通向后院，南边是西练武场。
LONG);
	set("exits", ([
		"east" : __DIR__"wg_shilu-4",
		"west" : __DIR__"wg_wuchang3",
	]));
	set("outdoors", "wuguan");
	set("coor/x", 31);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

