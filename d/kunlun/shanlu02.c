// Room: /d/kunlun/shanlu02.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "盘山路");
	set("long",@long
这是一条盘山的路，路边花草满地，路面似乎很久没有修整了，显
得有些破旧，但是从遗留的痕迹依稀可以看出当年的辉煌。南面是山下，
北面山上是昆仑派的所在。
long);
	set("exits",([
		"southdown" : __DIR__"shanlu01",
		"northup"   : __DIR__"shanlu03",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40010);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}