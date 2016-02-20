// Room: /d/kunlun/klshanlu.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "昆仑山麓");
	set("long",@long
整个昆仑山脉雪山连绵，冰河垂悬。远望昆仑，有如横卧云彩间的
银色玉龙。每年春天以后，冰雪融化，汇成了一股股清澈溪流，流入长
江，黄河。
long);
	set("exits",([
		"northup" : __DIR__"shanmen",
		"east"    : __DIR__"shankou",
//		"west"    : "/d/fairyland/shanlu1",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -120000);
	set("coor/y", 30000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}