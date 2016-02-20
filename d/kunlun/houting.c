// Room: /d/kunlun/houting.c
// Last Modified by winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
这里是后客厅，里面简单，只有几张软榻，供疲惫的客人歇息，屋
子里烤着火，暖烘烘的。
LONG );
	set("exits",([
		"north" : __DIR__"huayuan",
		"south" : __DIR__"jiuqulang5",
		"west"  : __DIR__"liangting",
		"east"  : __DIR__"jiashan",
	]));
	set("no_fight",1);
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119990);
	set("coor/y", 40120);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}