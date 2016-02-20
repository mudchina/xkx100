// Room: /lingzhou/jiangjungate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "大将军府");
	set("long", @LONG
这里是征东大将军赫连铁树的府第，在东大街的正中，对面就是衙
门。一色高檐大屋，两个校尉看上去彪悍骁勇，此刻正神气活现的挎着
弯刀守在门前。
LONG );
	set("exits", ([
		"north" : __DIR__"dongdajie",
		"south" : __DIR__"jjdayuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("coor/x", -17950);
	set("coor/y", 32060);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && objectp(present("xiao wei", environment(me))))
		return notify_fail("校尉挡住了你的去路：大将军不在府上！\n");

	return ::valid_leave(me, dir);
}
