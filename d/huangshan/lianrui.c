// Room: /d/huangshan/lianrui.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "莲蕊峰");
	set("long", @LONG
莲蕊峰与莲花峰相互依托，这里恰似莲花之蕊，峰不高，可怪石参
差不齐，高低起伏，甚是难走，而且并无胜景，所以游人罕至。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"yuping",
	]));
	set("objects", ([
		__DIR__"obj/guai" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
