// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "青竹林");
	set("long", @LONG
这是一片茂密的青竹林，一走进来，你仿佛迷失了方向。
LONG );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"ml4",
		"south" : __DIR__"dongmen",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", 70);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}