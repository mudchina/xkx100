// Room: /huanghe/wuqiao.c
// Java Sep. 22 1998

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "乌鞘岭");
	set("long", @LONG
乌鞘岭是武威东南的一个险要地段，黑石山上密林重重，时常有野
兽出没。一条官道从山下蜿蜒而过。
LONG );
	set("exits", ([
		"south"     : __DIR__"dacaigou",
		"northwest" : __DIR__"wuwei",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yongdeng");
	set("coor/x", -9000);
	set("coor/y", 6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}