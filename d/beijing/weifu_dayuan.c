// /beijing/weifu_dayuan.c
// Last modified by winder 2003.10.10

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "韦府大院");
	set("long", @LONG
这是鹿鼎公府正厅前面一个宽阔的大院，大院里种植着各类花草，
假山水池，琼楼高台，非常豪华。院内打扫得非常干净，韦府里的下人
穿梭其中，北边是一条木制走廊，通往康府的大厅。
LONG );
	set("exits", ([
		"south" : __DIR__"weifu_zoulang1",
		"north" : __DIR__"weifu_zoulang2",
	]));
	set("objects", ([
		__DIR__"npc/yuanding" : 1,
	]));
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
