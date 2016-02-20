// Room: /d/nanshaolin/talin8.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "塔林");
	set("long", @LONG
这里是少林历代僧侣的墓地，上百座墓塔式样繁多，造型各异。你
置身其中，只看得眼花缭乱，不知该往哪个方向走，你似乎迷路了。
LONG );
	set("exits", ([
		"northeast" : __DIR__"talin"+(random(10)+1),
		"southeast" : __DIR__"talin"+(random(10)+1),
		"northwest" : __DIR__"talin"+(random(10)+1),
		"southwest" : __DIR__"talin"+(random(10)+1),
		"south"     : __DIR__"talin9", 
		"west"      : __DIR__"talin"+(random(10)+1),
		"north"     : __DIR__"talin"+(random(10)+1),
		"east"      : __DIR__"talin7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1770);
	set("coor/y", -6190);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

