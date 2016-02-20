//libu2.c  礼部

inherit ROOM;

void create()
{
	set("short", "礼部公署");
	set("long", @LONG
这里是六部之三--礼部官员候朝的朝房.
LONG
	);
        set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"youmen",
	]));
	set("coor/x", -190);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}