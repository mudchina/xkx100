// Room: qiyiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "棋艺厅");
	set("long", @LONG
这里是棋艺厅，朝北的栏外是个小花园，绿草如茵，长枝委地，赌
场的繁杂声响，在这里都消失了。所有进出的人，也都屏息静气的。偶
尔有其他厅室来人心里不爽，过来发疯，立马就招人架了出去。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("exits", ([
		"west"       : __DIR__"weiqishi",
		"east"       : __DIR__"xiangqishi",
		"northwest"  : __DIR__"haizhanqi",
		"northeast"  : __DIR__"feixingqi",
		"south"      : __DIR__"zoulang2",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
