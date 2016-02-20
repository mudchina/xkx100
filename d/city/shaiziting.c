// Room: shaiziting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "骰子厅");
	set("long", @LONG
这里是赌场的骰子厅，四周人进人出的，紧闭的门开启的时候，便
从屋里传出一阵阵清脆的骰子弹落声。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("exits", ([
		"west"      : __DIR__"shaiziroom",
		"east"      : __DIR__"yacairoom",
		"south"     : __DIR__"duchang",
		"north"     : __DIR__"daxiaoroom",
		"northeast" : __DIR__"dahua",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
