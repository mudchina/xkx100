// Room: /d/taiwan/ningnanfang.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "宁南坊");
	set("long", @LONG
郑经治台时，在台湾府以赤嵌一带为中心，将市街划分为四坊，台
湾归清后，仍保留郑氏设置之四坊，宁南坊乃赤嵌城南部一坊。
LONG );
	set("exits", ([
		"north" : __DIR__"chiqian",
		"south": __DIR__"dagougang",
	]));
	set("objects", ([
		__DIR__"npc/bing": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

