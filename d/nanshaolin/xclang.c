// Room: /d/nanshaolin/xclang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","石廊");
	set("long", @LONG
一条青石砌成的走廊，周围并无半分饰物，但石色天青，石壁清凉。
踏在石面之上，空谷足音，令人暇想不已。清风送爽，传来阵阵幽香，
不由使人尘俗皆忘。
LONG );
	set("exits", ([
		"east"      : __DIR__"xctang",
		"northwest" : __DIR__"gygu",	
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
