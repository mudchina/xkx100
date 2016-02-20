// Room: /d/songshan/shandao1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "中岳山道");
	set("long", @LONG
你走在嵩山中岳山道上，青松翠柏，山风岚雾，时来飘荡。左边通
往启母石，右手是卢崖瀑布。
LONG );
	set("exits", ([
		"southdown" : __DIR__"dadian",
		"northwest" : __DIR__"qimushi",
		"northeast" : __DIR__"luyasi",
		"southeast" : __DIR__"yunutai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", 0);
	set("coor/y", 740);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
