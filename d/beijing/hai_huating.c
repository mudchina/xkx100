// /beijing/hai_huating.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府花厅");
	set("long", @LONG
这个花厅是喝酒赏月的佳所，一个小亭子建造在厅的中央，四周围
绕着一些葡萄藤。一阵微风吹过，空气中似乎有隐隐的花香飘来，中人
欲醉。
LONG );
	set("exits", ([
		"west" : __DIR__"hai_dayuan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -220);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
