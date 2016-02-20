// Room: /d/yanping/beimenling.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "北门岭");
	set("long", @LONG
延平府北城墙建与山崖绝壁之间，蜿蜒起伏于北门岭间。背后就是
高达天际的茫荡山了，从此西下进入溪源十里画廊，直达茫荡深处的溪
源。
LONG );
	set("exits", ([
		"northwest" : __DIR__"youlang",
		"southdown" : __DIR__"meishanpo",
	]));
	set("outdoors", "jiangnan");
	set("no_clean_up", 0);
	set("coor/x", 1480);
	set("coor/y", -6160);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
