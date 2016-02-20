// Room: /d/city/jiaowai4.c
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
		"north"	 : __DIR__"jiaowai3",
		"west"	  : __DIR__"jiaowai5",
		"southeast" : "/d/yixing/shulin1",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/zhao-gouer" : 1,
		__DIR__"obj/shuzhi": 2,
		__DIR__"obj/shitou": 2,
	]));
	set("coor/x", 70);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
