// libu.c 吏部

inherit ROOM;

void create()
{
	set("short", "吏部公署");
	set("long", @LONG
这里是六部之首--吏部官员候朝的朝房.
LONG
	);
	set("exits", ([
		"south" : __DIR__"youmen",
	]));
	set("objects", ([
		__DIR__"npc/suoetu" : 1,
	]));
	set("coor/x", -190);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}