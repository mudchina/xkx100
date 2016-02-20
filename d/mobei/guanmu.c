// Room: /d/mobei/guanmu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "灌木丛");
	set ("long", @LONG
脚下走动时掠过长长的茅草，身边是高高矮矮的灌木丛。你叫不出
名目来，也看不清楚四边的景色，只有一条小路在灌木丛中时隐时现地
伸向小土丘的山顶。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"guanmu1",
		"westup"    : __DIR__"hill",
	]));
	set("coor/x", -250);
	set("coor/y", 5160);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
