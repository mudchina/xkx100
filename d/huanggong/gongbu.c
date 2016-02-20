//ROOM : gongbu.c

inherit ROOM;

void create()
{
	set("short", "工部公署");
	set("long", @LONG
这里是六部之六--工部官员候朝的朝房.
LONG
	);
        set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"zuomen",
	]));
	set("coor/x", -210);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}