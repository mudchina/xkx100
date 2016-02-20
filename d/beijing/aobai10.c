// /d/beijing/aobai10.c
// Last Modified by winder on Jan. 18 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厂暗道");
	set("long", @LONG
这是一条暗道，是专为鳌拜从鳌府直接到东厂用的。南边是一扇木
门(door)。
LONG );
	set("exits", ([
		"south"     :  __DIR__"aobai6",
		"northeast" : __DIR__"aobai11",
	]));
	set("item_desc", ([
		"door" : "这是一扇极厚的木门。\n",
	]));
	create_door("south", "木门", "north", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
