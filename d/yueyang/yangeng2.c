// Room: /d/yueyang/yangeng2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岩梗");
	set("long", @LONG
这是香炉山通往酒香山上酒香亭的岩梗小道。香炉山与君山本是一
脉相通，不可分割，冬春水枯季节，一条数十丈的岩埂由君山直通香炉
山。这条岩埂原是一条小山脊，横跨于两山之间，后经千百年湖水冲洗
荡涤，山脊泥土逐渐被浪涛洗尽，以至岩埂裸露，非水枯不可往来。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"yangeng1",
		"southup" : __DIR__"xianglushan",
	]));
	set("coor/x", -1800);
	set("coor/y", 2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
