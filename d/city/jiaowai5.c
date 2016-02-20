// Room: /d/city/jiaowai5.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
扬州郊外的茂密树林，阴森可怖。抬头不见天日。这里也是扬州命
案发生最多的地方。鸟兽蛇虫游荡不穷。
LONG );
	set("exits", ([
		"east"  : __DIR__"jiaowai4",
		"west"  : __DIR__"jiaowai6",
	]));
	set("objects", ([
		__DIR__"obj/shuzhi": 2,
		__DIR__"npc/dushe" : 1,
	]));
	set("coor/x", 60);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}