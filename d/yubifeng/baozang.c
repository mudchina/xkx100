// /yubifeng/baozang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "闯王宝藏");
	set("long", @long
一踏进石门，一阵金光照射，人人眼花撩乱，凝神屏气，个个张大
了口合不拢来。原来里面竟是个极大的洞穴，四面堆满了金砖银块，珍
珠宝石，不计其数。只是金银珠宝都隐在透明的坚冰之后。料想当年闯
王的部属把金银珠宝藏入之后，浇上冷水。该地终年酷寒，坚冰不融，
金珠就似藏在水晶之中一般。
long );
	set("exits", ([
		"out" : __DIR__"shimen",
	]));
	set("objects", ([
		JEWELRY_DIR+"maoeryan" : 1,
		JEWELRY_DIR+"manao" : 1,
		JEWELRY_DIR+"biyu" : 1,
		JEWELRY_DIR+"zhenzhu" : 1,
		JEWELRY_DIR+"shanhu" : 1,
		JEWELRY_DIR+"zumulv" : 1,
		JEWELRY_DIR+"feicui" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", 6110);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
