// Room: /d/quanzhou/tumenshuiguan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "涂门水关");
	set("long", @LONG
这是去往港口的主要通道，横跨小溪之上，巍然矗立，可谓巧手天
成，别具一格。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"tumenji",
		"east" : __DIR__"lingshan",
	]));
	set("coor/x", 1870);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
