// /beijing/hai_houyuan.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府后院");
	set("long", @LONG
这里是海澄公府大厅后侧的一个小花园，杂乱地种着各种花草，看
来无人打理，杂草已经长得很高了。一些鲜花夹杂在草丛中，阵阵花香
不断地飘过。
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dating",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
