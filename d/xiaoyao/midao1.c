// midao1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "秘密通道");
	set("long", @LONG
这是一段又长又黑的秘密通道，隐约可以感觉到四周是冰冷而坚硬
的石壁，你什么了看不清楚，只可以靠摸索着前进。
LONG );
	set("exits", ([
		"out" : __DIR__"shishi3",
		"north" : __DIR__"midao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -10000);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
