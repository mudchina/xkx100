// Room: /d/huanggong/zuomen.c

inherit ROOM;

void create()
{
	set("short", "左阙门");
	set("long", @LONG
这是通往各部官员朝房的左门. 西庑房设的是兵、刑、工三部.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"east"  : __DIR__"dianwai",
		"west"  : __DIR__"xingbu",
		"north" : __DIR__"bingbu",
		"south" : __DIR__"gongbu",
	]));
        set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}