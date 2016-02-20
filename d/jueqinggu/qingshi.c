// Room: /d/jueqinggu/qingshi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这是公孙止的睡房，里面的床上绫罗绸缎，床边站着一名丫鬟，窗
户半开，屋内光线不太明亮。
LONG
	);

	set("exits", ([
		"south" : __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -550);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

