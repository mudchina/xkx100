//ROOM: /d/yanziwu/huizhen.c

inherit ROOM;

void create()
{
	set("short", "汇珍园");
	set("long",@LONG
这是燕子坞中最大的花园，遍植江南的奇花异草，香气浓郁。一群
彩蝶在花间翩跹飞舞，你不由的痴了，有点乐而忘返。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"west"  : __DIR__"changlang",
	]));
	set("objects",([
		__DIR__"npc/hudie" : 3,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 850);
	set("coor/y", -1520);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}