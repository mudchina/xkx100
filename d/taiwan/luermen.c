// Room: /d/taiwan/luermen.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "鹿耳门");
	set("long", @LONG
清政府治台之初，以台湾孤悬海外，易为奸民捕逃之薮，而禁止移
民，后因私渡日多，乃予开放，但仅限福建厦门与台南鹿耳门两岸独口
对渡，因此府治成为全台唯一的吐纳港。此情况直至鹿港、八里坌开港
后始有改变。
LONG );
	set("exits", ([
		"east" : __DIR__"anping",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taiwan");
	set("coor/x", 2490);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

