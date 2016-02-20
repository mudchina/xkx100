// /d/beijing/andao6.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地会暗道");
	set("long", @LONG
地道里一片漆黑，呼呼的风声从四面八方传来。你什么也看不见，
只能在地道里瞎摸乱撞。东面似乎隐隐约约有人说话，但只一会儿又没
声了。你使劲地摇了摇头，很怀疑这到底是不是幻觉。好象你已经迷路
了。
LONG );
	set("exits", ([
		"west"  : __DIR__"andao4",
		"east"  : __DIR__"andao7",
		"north" : __DIR__"andao5",
		"south" : __DIR__"andao8",		
	]));
	set("no_clean_up", 0);
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
