// Room: /d/huanggong/xingbu.c

inherit ROOM;

void create()
{
	set("short", "刑部公署");
	set("long", @LONG
这里是六部之五--刑部官员候朝的朝房.
LONG
	);
        set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"zuomen",
	]));
	set("coor/x", -220);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}