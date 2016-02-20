// shiji5.c
// Modified by Winder June.25 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "石级");
	set("long", @LONG
又行二百馀级，水声已然振耳欲聋，前面并有光亮透入。走到石级
的尽头，前面是个仅可容身的洞穴，探头向外一眼望出去，外边怒涛汹
涌，水流湍急，竟是一条大江。江岸山石壁立，嶙峋巍峨，看这情势，
已是到了澜沧江畔。
LONG );
	set("exits", ([
		"westdown" : __DIR__"shiji4",
		"out"      : "/d/wanjiegu/riverside1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -21010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
