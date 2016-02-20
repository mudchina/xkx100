// Room: /city/biaojuhc.c

inherit ROOM;

void create()
{
	set("short", "货仓");
	set("long", @LONG
福威镖局武功并无出色之处，但福字当头，和黑白两道均极交好，
从未失镖。顾主的货物在这里堆积如山。镖局的伙计们正在手忙脚乱的
往镖车上装载货物。虽然每个伙计都已尽力而为，但还是忙不过来。
LONG
        );
	set("exits", ([
		"west"  : __DIR__"biaojudy",
		"north" : __DIR__"biaojuzf",
	]));
	set("objects", ([
		__DIR__"npc/qian" : 1,
		__DIR__"npc/huo" : 1,
	]));
	set("coor/x", 1831);
	set("coor/y", -6298);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
