// Room: /d/nanshaolin/fota1.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "佛塔一层");
	set("long", @LONG
你进到佛塔里面，四周阴暗，寂静无声，隐约看到正中有一尊积满
灰尘，蛛网密布的佛龛。忽然一阵冷风不知从哪吹了过来，你不禁打了
个寒蝉。
LONG );
	set("exits", ([
		"up"  : __DIR__"fota2", 
		"out" : __DIR__"fotaout",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

