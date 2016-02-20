// Room: /d/xingxiu/shazhou.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "沙洲");
	set("long", @LONG
这里是敦煌城所在地，是丝绸之路上的咽喉重镇。四面城墙高耸，
另有高出城墙一倍的城墩。城内混居了周围的多个民族，走在大街上看
到和听到的无不透着新奇。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"silk4",
		"west"      : __DIR__"tugu",
		"northup"   : __DIR__"rentou",
	]));
	set("no_clean_up", 0);
	set("coor/x", -23000);
	set("coor/y", 900);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";
