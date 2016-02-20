// /d/shenlong/zoulang.c 走廊
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条石走廊，南面通向大厅，北面是练武场，两边是用石柱撑
的凉棚，挂满树叶、青藤，边上有许多小石凳可供人休息。一些凳子上
面三三两两地坐了许多神龙教的弟子，正在七嘴八舌地谈论着什么。
LONG
	);
	set("outdoors", "shenlong");
	set("exits", ([
		"south": __DIR__"dating",
		"north": __DIR__"wuchang",
	]));

	set("objects", ([
		__DIR__"npc/mujianping" : 1,
	]));
	setup();
	replace_program(ROOM);
}
