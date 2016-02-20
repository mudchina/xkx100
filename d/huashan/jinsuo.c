// jinsuo.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "金锁关");
	set("long", @LONG
金锁关山势形如一把锁，下面是一片开阔地，两旁是高耸入云的峭
壁，中间一条羊肠小道。真是一夫当关，万夫莫开。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"southup"   : __DIR__"zhenyue",
		"northdown" : __DIR__"shangtianti",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 200);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
