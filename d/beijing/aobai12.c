// /d/beijing/aobai12.c
// Last Modified by winder on Jan. 18 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "东厂暗道");
	set("long", @LONG
这是一条暗道，是专为鳌拜从鳌府直接到东厂用的。
LONG );
	set("exits", ([
		"southwest" : __DIR__"aobai11",
		"northeast" : __DIR__"bingqiku",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
