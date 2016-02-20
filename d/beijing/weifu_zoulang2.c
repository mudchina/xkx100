// /beijing/weifu_zoulang2.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "韦府走廊");
	set("long", @LONG
这是一条木制的走廊，地面很是光滑，被打整得一尘不染。几个韦
府的下人在此走动。南边是个巨大的花园，北边就是韦府的大厅。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_dating",
		"south" : __DIR__"weifu_dayuan",
	]));

	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
