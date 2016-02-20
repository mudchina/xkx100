// Room: /d/nanshaolin/xiaolu-2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
你走在一条碎石铺成的小路上，两侧青草茵茵，山花烂漫。空气中
夹带着泥土的芳香，扑面而来。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"south"     : __DIR__"xiaolu-3",
		"northwest" : __DIR__"xiaolu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6300);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

