// Room: /d/mobei/lvzhou.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "绿洲");
	set ("long", @LONG
一块沙漠中的绿洲，虽然只有很小的一块，但对于沙漠中的旅行者
而言却已足够。你终于可以停下来歇歇脚了。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"southeast" : __DIR__"damo2",
		"north"     : __DIR__"damo",
	]));
	set("coor/x", -210);
	set("coor/y", 5120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
