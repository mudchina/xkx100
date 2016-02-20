// Room: /d/taiwan/zhenbeifang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "镇北坊");
	set("long", @LONG
郑经治台时，在台湾府以赤嵌一带为中心，将市街划分为四坊，台
湾归清后，仍保留郑氏设置之四坊，镇北坊乃赤嵌城北部一坊。
LONG );
	set("exits", ([
		"northwest" : __DIR__"anping",
		"northeast" : __DIR__"zhuluo",
		"south"     : __DIR__"chiqian",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
		__DIR__"npc/shangren": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

