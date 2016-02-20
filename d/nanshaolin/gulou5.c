// Room: /d/nanshaolin/gulou5.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓楼五层");
	set("long", @LONG
一眼望去，只见蓝天白云，青山列列，令人将尘俗之气，顿为一一
扫。南至前三殿，北到戒台，整个少林寺尽在眼底。北面槐树林随风起
伏，犹如一片林海。东西面围绕全寺的是密密匝匝的松林，一眼往不到
边。
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou6",
		"down" : __DIR__"gulou4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

