// Room: /d/quanzhou/road2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
这是泉州的一条干道，两边种着凤凰木，人马川流不息。南去可达
海外交通使节府，东面是万国烟雨楼。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"east"   : __DIR__"yanyu",
		"north"  : __DIR__"road1",
		"south"  : __DIR__"shibosi",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1860);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
