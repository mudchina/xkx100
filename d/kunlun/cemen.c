// Room: /d/kunlun/cemen.c
// Last Modified by winder on Nov. 15 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "侧门");
	set("long", @LONG
绕过三圣堂的后花园，经过一条曲曲折折的花径，又穿入许多厅堂
之中。但见屋宇连绵，门户复叠，到了昆仑派的侧门。
LONG );
	set("exits", ([
//		"west"  : __DIR__"klshanlu1",
//		"north" : __DIR__"westxiangfang",
		"east"  : __DIR__"huayuan",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119991);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}