// Room: /d/city/jiaowai12.c
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
		"south" : __DIR__"jiaowai10",
		"west"  : __DIR__"jiaowai13",
	]));
	set("objects", ([
		__DIR__"npc/dushe" : 2,
		__DIR__"obj/shuzhi": 1,
	]));
	set("coor/x", 20);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}