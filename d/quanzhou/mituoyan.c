// Room: /d/quanzhou/mituoyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "弥陀岩");
	set("long", @LONG
这里古木参天，巨石峭立。多雨时节，有飞瀑如练，从岩上垂挂下
来，溅起千堆细沫，诗云：虹雨千层吹不断，琉璃万盅涌还多。瀑边两
大巨石夹峙，岩壁小松攀生，仰望天空细如一线，即为「一线天」之所
在。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"liandanshi",
		"northwest" : __DIR__"qianshouyan",
	]));
	set("coor/x", 1830);
	set("coor/y", -6400);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
