// Room: /huanghe/tumenzi.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "土门子");
	set("long", @LONG
土门子也是以前驻军的地方，周围全是沙漠，中间一块小小的绿洲，
本来这里有当地的牧民居住，可是前不久来了一伙马贼占据了这里以这
里为大本营四出劫掠，无恶不作。
LONG );
	set("exits", ([
		"south"     : __DIR__"wuwei",
		"northeast" : __DIR__"shixiazi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -23000);
	set("coor/y", 10000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
