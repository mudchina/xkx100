// Room: /d/nanshaolin/talin11
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "塔林");
	set("long", @LONG
这里是少林历代僧侣的墓地，上百座墓塔式样繁多，造型各异。你
置身其中，只看得眼花缭乱，不知该往哪个方向走，你似乎迷路了。
LONG
	);

	set("exits", ([
                "northeast" : __DIR__"talin10",
		"southeast" : __DIR__"talin"+(random(10)+1),
		"northwest" : __DIR__"talin"+(random(10)+1),
		"southwest" : __DIR__"talin"+(random(10)+1),
		"south"     : __DIR__"talin"+(random(10)+1), 
                "west"      : __DIR__"talin"+(random(10)+1),
                "north"     : __DIR__"fotaout",
                "east"      : __DIR__"talin"+(random(10)+1),
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

