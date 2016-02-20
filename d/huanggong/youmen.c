// Room: /d/huanggong/youmen.c

inherit ROOM;

void create()
{
	set("short", "右阙门");
	set("long", @LONG
这是通往各部官员朝房的右门. 东庑房设的是吏、户、礼三部.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"west"  : __DIR__"dianwai",
		"east"  : __DIR__"hubu",
		"north" : __DIR__"libu",
		"south" : __DIR__"libu2",
	]));
        set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}