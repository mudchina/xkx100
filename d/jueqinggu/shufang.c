// Room: /d/jueqinggu/shufang.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这是公孙止的书房，书架上放着一些武林秘籍，一般很少有人能够
进来。
LONG
	);

	set("exits", ([
		"south" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -540);
	set("coor/y", -350);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

