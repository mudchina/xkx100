// /guanwai/milin2.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
这是一片茂密的松林，杂乱的生长在倾斜的山坡上。每棵松树都有
三四抱粗细，高达十几丈。树冠枝多叶密，将天空完全遮住，因此林内
显得有些昏暗。树木之间长着很多灌木杂草，使行走很艰难，据说人参
就生长在这些杂草之中。
LONG );
	set("exits", ([
		"westdown" : __DIR__"milin1",
		"southup"  : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/dongbeihu": 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}