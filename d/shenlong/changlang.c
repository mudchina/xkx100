// /d/shenlong/changlang.c 长廊
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是一条长廊，西面通向大厅，东面是峰顶，周围挂满了树叶、青
藤，边上有许多小石凳可供人休息。一些凳子上面三三两两地坐了许多
神龙教的弟子，正在七嘴八舌地谈论着什么。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"east": __DIR__"tingkou",
		"west": __DIR__"fengding",
	]));

	set("objects", ([
		__DIR__"npc/fang" : 1,
	]));
	setup();
	replace_program(ROOM);
}
