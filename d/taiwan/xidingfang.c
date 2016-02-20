// Room: /d/taiwan/xidingfang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "西定坊");
	set("long", @LONG
郑经治台时，在台湾府以赤嵌一带为中心，将市街划分为四坊，台
湾归清后，仍保留郑氏设置之四坊，西定坊乃赤嵌城西部一坊。
LONG );
	set("exits", ([
		"east" : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

