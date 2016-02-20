// Room: /d/xingxiu/.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;

void create()
{
	set("short", "人头疙瘩");
	set("long", @LONG
这里是黄黏土地带。是风蚀台地得自然景象。周围皆人迹罕至的戈
壁滩。因地处风带线上，常年多刮大风，泥土剥蚀，留下坚硬和有红柳
草根的部分，形成土墩，星罗棋布，酷似人头，故有此称。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southdown" : __DIR__"shazhou",
		"southeast" : __DIR__"yanzhishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -23000);
	set("coor/y", 1000);
	set("coor/z", 100);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

