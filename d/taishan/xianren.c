// Room: /d/taishan/xianren.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "仙人桥");
	set("long", @LONG
仙人桥在爱身崖西侧。两崖对峙，下临深涧，中有三石衔接抵撑而
成桥状。
LONG );
	set("exits", ([
		"northeast" : __DIR__"aishen",
		"south"     : __DIR__"wanghai",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 360);
	set("coor/y", 750);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
