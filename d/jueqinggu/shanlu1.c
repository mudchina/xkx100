// Room: /d/jueqinggu/shanlu1.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
着是一条陡峭的山路，向后山蜿蜒而去。
LONG
	);

	set("exits", ([
		"northup"   : __DIR__"shanlu2",
		"southdown" : __DIR__"songtang",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -350);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

