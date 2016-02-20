// Room: /d/kunlun/shanlu01.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "昆仑山路");
	set("long",@long
这里已经是昆仑派的地方了，路边花草满地，虽然是寒冬，这里却
仍然生机勃勃，到处传来鸟兽的叫声，前面山上就是昆仑派的居所了，
下面是来的时候的山门。
long);
	set("exits",([
		"westdown" : __DIR__"shanmen",
		"northup"  : __DIR__"shanlu02",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}