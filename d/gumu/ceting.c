// ceting.c 侧厅
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
	set("short", "侧厅");
	set("long", @LONG
这里是古墓的侧厅，密封得严严实实，没有一丝的缝隙。在昏暗的
灯光下，很难看清楚厅里的陈设。
LONG	);
	set("exits", ([
		"east"  : __DIR__"mudao20",
		"north" : __DIR__"mudao19",
		"south" : __DIR__"mudao23",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3180);
	set("coor/y", -10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}

