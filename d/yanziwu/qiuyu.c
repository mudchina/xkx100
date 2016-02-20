// Room: /d/yanziwu/qiuyu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "秋雨斋");
	set("long", @LONG
秋雨斋高居山崖之上，下面十数丈就是太湖的水面了。蔓陀山庄中
秋赏月时光，借着水音，高扬丝竹，明月当空，万顷如银蛇，真是无边
景致应时来，恍若人间仙境。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown"   : __DIR__"path19",
	]));
	set("coor/x", 1190);
	set("coor/y", -1260);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}