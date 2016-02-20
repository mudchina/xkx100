// Room: /city/hangou1.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗沟边");
	set("long", @LONG
沿古邗沟继续东行，可以看到水面上有许多官船和富商的包船，船
中不时传出阵阵嬉笑之声。与这些船同行的还有许多吃水深不少的货船，
这大抵是北货运到扬州来出售的，也有是淮南的土产。不少盐船把各地
盐场收来的盐运送到这个淮南东路的治所来，使得这里的水面拥挤不堪。
LONG );
	set("exits", ([
		"west" : __DIR__"hangou2",
		"east" : __DIR__"hangou0",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

