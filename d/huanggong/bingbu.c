// Room: /d/huanggong/bingbu.c

inherit ROOM;

void create()
{
	set("short", "兵部公署");
	set("long", @LONG
这里是六部之四--兵部官员候朝的朝房.
LONG
	);
        set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"zuomen",
	]));
	set("objects", ([
		__DIR__"npc/mingzhu" :1,
	]));
	set("coor/x", -210);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}