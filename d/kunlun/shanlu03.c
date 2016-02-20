// Room: /d/kunlun/shanlu03.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "盘山路");
	set("long",@long
这是一条盘山的路，山间穿来鸟鸣兽叫，路面似乎已很久没有修整
了，显得有些破旧，但是从遗留的痕迹依稀可以看出当年的辉煌。南面
是山下，北面山上是昆仑派的所在。
long);
	set("exits",([
		"southdown" : __DIR__"shanlu02",
		"northup"   : __DIR__"shanlu04",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40020);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}