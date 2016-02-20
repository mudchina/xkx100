// /d/xingxiu/silk1.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是一条中原和西域之间的商道。迎面而来的是一个个沙包，星罗
棋布於荒原之上。一阵风沙吹过，象刀割一样撕裂着你的脸。东边有一
座雄伟的关隘，西面则通往西域。
LONG );
	set("outdoors", "silu");
	set("exits", ([
		"east"      : __DIR__"jiayuguan",
		"northwest" : __DIR__"chouchishan",
		"southwest" : __DIR__"xianrenya",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -19000);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

