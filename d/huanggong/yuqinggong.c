// yuqinggong.c

inherit ROOM;

void create()
{
	set("short", "毓庆宫");
	set("long", @LONG
这儿是皇太子读书的地方. 太子年幼, 不肯用功, 于是皇上就找来
一些皇族的幼儿来陪太子.
LONG
	);
	set("exits", ([
		"north"   : __DIR__"fengxianmen",
		"east"    : __DIR__"huangjimen",
		"west"    : __DIR__"rijing",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}