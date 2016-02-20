// Room: /d/nanshaolin/xiaolu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "碎石小路");
	set("long", @LONG
你走在一条碎石铺成的小路上，两侧青草茵茵，山花烂漫。空气中夹带
着泥土的芳香，扑面而来。南面有一片很大的菜园子。
LONG );
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"cyzi-1",
		"north" : __DIR__"xiaolu-2",
	]));
	set("coor/x", 1870);
	set("coor/y", -6310);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

