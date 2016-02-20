// Room: /yangzhou/kedian.c
// Last Modified by Winder on Jul. 15 2000
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", YEL"孔雀工作室"NOR);
	set("long", @LONG
这里是孔雀的家。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("exits", ([
		"out"    : "/d/city/kedian",
	]));

	setup();
	"/clone/board/news_b"->foo();
}
