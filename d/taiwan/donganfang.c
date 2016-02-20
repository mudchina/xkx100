// Room: /d/taiwan/donganfang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "东安坊");
	set("long", @LONG
郑经治台时，在台湾府以赤嵌一带为中心，将市街划分为四坊，台
湾归清后，仍保留郑氏设置之四坊，东安坊乃赤嵌城东部一坊。
LONG );
	set("exits", ([
		"west" : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
//		__DIR__"npc/shangren": 1,
//		__DIR__"npc/pingpuren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -7050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

