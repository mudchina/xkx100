// Room: /d/yanziwu/bridge.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "碧玉小桥");
	set("long", @LONG
碧玉小桥横跨在清溪之上。桥下溪水清如翡翠，温如润玉。汉白玉
小桥上爬满青藤，满目生绿，十分可人。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"west"  : __DIR__"path2",
		"east"  : __DIR__"path3",
	]));
	set("objects", ([
		__DIR__"npc/xiaolan" : 1,
	]));
	set("coor/x", 1220);
	set("coor/y", -1290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}