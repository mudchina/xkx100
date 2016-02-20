// /d/xingxiu/silk2.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "丝绸之路");
	set("long", @LONG
这是闻名中外的丝绸古道，一条连接中原和西域之间的商道。南面
连绵的祁连山脉在阳光的照射下好像是一条玉带。迎面而来的是一个个
沙包，星罗棋布於荒原之上。一阵风沙吹过，象刀割一样撕裂着你的脸。
东南过仇池山通往嘉峪关，西面穿过颂摩崖，则通往西域。
LONG );
	set("outdoors", "silu");
	set("exits", ([
	    "south"     : __DIR__"chouchishan",
	    "westup"    : __DIR__"songmoya",
	]));
	set("objects", ([
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -20000);
	set("coor/y", 600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

