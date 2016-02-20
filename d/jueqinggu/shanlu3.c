// Room: /d/jueqinggu/shanlu3.c
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
		"northup"  : __DIR__"duanchangya",
		"eastdown" : __DIR__"shanlu2",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -540);
	set("coor/y", -340);
	set("coor/z", 40);
	setup();
	replace_program(ROOM); 
}

