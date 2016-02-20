// /kaifeng/gongmen.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "石拱门");
	set("long", @LONG
用石头搭起来的一个拱门，高越两丈，上面镂刻云纹。两边是拴马
的石柱。再往前边一点的地方，有块旗杆石，那是由两块巨大的石头，
一半埋到地下，在和口的地方，有个大孔可以插旗杆。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"southup" : __DIR__"8bao",
		"northdown" : __DIR__"road1",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
