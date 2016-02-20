// Room: /huanghe/tiandi4.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "田地");
	set("long", @LONG
这里是一大片农田。不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。村里不时传出一声声的
犬吠。
LONG );
	set("exits", ([
		"southwest" : __DIR__"tiandi3",
		"north"     : __DIR__"huanghe1",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	set("coor/x", -190);
	set("coor/y", 510);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}