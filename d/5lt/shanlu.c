// Room: /d/5lt/shanlu.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条上山的小路。小路两边杂草丛生，看来少有行人。不过路
泥却甚是平滑，倒像常有人来往一般。前面是个铁丝网，过了铁丝网就
是五老峰了，你不由加快了脚步。
LONG );
	set("exits", ([
		"eastup"   : __DIR__"5laofeng",
		"westdown" : __DIR__"caodi",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -115);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}