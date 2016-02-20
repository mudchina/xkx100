// shishi2.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石室");
	set("long", @LONG
这是一个石头砌成的房间，因为好久没有人来过，散发着一些很难
闻的气味，房间中到处可以看到蛛丝和虫迹。
LONG );
	set("exits", ([
		"north" : __DIR__"shiji3",
		"west" : __DIR__"shiji2",
	]));
	create_door("north", "石门", "south", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}