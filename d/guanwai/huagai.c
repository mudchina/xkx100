// /guanwai/huagai.c

inherit ROOM;

void create()
{
	set("short", "华盖峰");
	set("long", @LONG
长白东侧最高峰，自古以来，华盖峰就是风雨云雾的故道。云雾起
处，恰似掀开锅盖一般，雾气翻滚，池水云天，一脉相连，气壮华夏，
故名华盖峰。
LONG );
	set("exits", ([
		"north"     : __DIR__"tianhuo",
		"westdown"  : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6200);
	set("coor/y", 5170);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}