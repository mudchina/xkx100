// Last Modified by Sir on May. 22 2001
// liangong.c 练功房

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
这里是恒山派弟子练功的房间。房间中央立着几个练功用的木人。
LONG );

	set("exits", ([
		"south" : __DIR__"byaeast",		
	]));
	
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", 50);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
}

