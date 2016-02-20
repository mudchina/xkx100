// Room: /d/kunlun/shilu1.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long",@long
这是一条铺的十分平整的石板路，路面打扫的干干净净，北面过去
是个花园，传来阵阵花香。
long);
	set("exits",([
		"south" : __DIR__"qianting",
		"north" : __DIR__"huayuan1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "kunlun");
	set("coor/x", -119990);
	set("coor/y", 40070);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}