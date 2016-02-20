// Room: /d/hengshan/xuangengsong.c
// Date: Oct. 2 1997 by That

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "悬根松");
	set("long", @LONG
就在虎风口这个风口险地，却有一株古松，虽被大风吹得树根裸露，
千百年来仍迎风挺立，这就是恒山著名的“梵宫悬根”。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"east"      : __DIR__"hufengkou",
	]));
	set("objects", ([
		"/clone/medicine/vegetable/chaihu" : random(2),
	]));
	set("outdoors", "hengshan");
	set("coor/x", 10);
	set("coor/y", 3150);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

