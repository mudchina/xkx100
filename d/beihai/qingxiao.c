// /d/beihai/qingxiao.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "庆宵楼");
	set("long", @LONG
这座庆霄楼为一踞山半之二层建筑，歇山顶。上层四周挑廊，是冬
日观冰嬉之所。站在这里可以清楚的看见琼岛以西的景色。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"yuexin",
		"northdown" : __DIR__"yuegu",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 4090);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
