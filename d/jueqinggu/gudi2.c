// Room: /d/jueqinggu/gudi2.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "绝情谷底");
	set("long", @LONG
你只觉阳光耀眼，花香扑鼻，竟是别有天地，他不即爬起，游目四
顾，只见繁花青草，便如同一个极大的花园，然花影不动，幽谷无人。
你又惊又喜，纵身出水，见十余丈外有几间茅屋。
LONG
	);
	set("exits", ([
		"enter" : __DIR__"maowu",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "tan di" ) return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;

	message_vision("$N纵身向寒潭跳了进去。\n", me);
	me->move(__DIR__"hantan1");
	tell_room(environment(me), me->name() + "从岸上跳了进来。\n", ({ me }));
	return 1;
}
