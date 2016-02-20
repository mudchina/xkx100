// Room: /beijing/aobai6.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "鳌拜卧房");
	set("long", @LONG
这是鳌拜的卧房。鳌拜躺在床上睡着了，粗声粗气地打着呼噜。
北边有一扇门(door)。
LONG );
	set("exits", ([
		"east" : __DIR__"aobai4",
		"north" : __DIR__"aobai10",
	]));
	set("item_desc", ([
		"door" : "这是一扇极厚的木门。\n",
	]));
	set("objects", ([
		__DIR__"npc/aobai" : 1,
	]));
	create_door("north", "木门", "south", DOOR_CLOSED);
	set("coor/x", -203);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
