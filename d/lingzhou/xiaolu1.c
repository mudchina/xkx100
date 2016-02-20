// Room: /lingzhou/xiaolu1.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "林中小路");
	set("long", @LONG
这是陡坡上的一条杂草丛生的羊肠小路，看起来平时没什么人迹，
路边开着不知名的野花，两边的松树依然高大、挺拔。阳光透下来照
的你身上是斑斑驳驳的影子。
LONG );
	set("exits", ([
		"south"     : __DIR__"dalu",
		"north"     : __DIR__"xiaolu2",
	]));
	set("objects", ([
		"/d/city/obj/shuzhi" : 1,
		"/d/wudang/npc/yetu" : 1,
	]));
	set("outdoors", "lingzhou");
	set("coor/x", -17930);
	set("coor/y", 32100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
