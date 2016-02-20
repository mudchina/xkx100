// Room: /d/kunlun/huapu.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","花圃");
	set("long", @LONG
这里是一个小花圃，种满了各种西域奇花异草，中原难得一见。
LONG
);
	set("exits", ([ 
		"north" : __DIR__"tieqinju",
		"west"  : __DIR__"huayuan",
	]));
	set("objects", ([
		__DIR__"obj/flower" : 2,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);

}