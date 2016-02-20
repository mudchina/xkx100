// Room: /d/nanshaolin/lhsuo.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIG"轮回所"NOR);
	set("long", @LONG
你一脚蹬开门看时，发现这里原来就是南少林寺的大东厕。里面秽
气畜人，正是五谷轮回之所。不过少林和尚十分勤快，气味虽重，地面
倒是打扫得非常干净。
LONG );
	set("exits", ([
		"west" : __DIR__ "songshu2",
        ]));
	set("objects", ([
		CLASS_D("nanshaolin")+"/fangyan" : 1,
        ]));
	set("coor/x", 1830);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

