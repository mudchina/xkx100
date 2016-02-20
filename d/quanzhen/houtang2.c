// houtang2.c 后堂二进
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后堂二进");
        set("long", @LONG
这里是全真教弟子平常研讨武功的地方，这个堂不大，由于经常
要在这里演武，索性连桌椅也全都靠到墙边去了，这样腾出了一大片
空地来。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang3",
                "west" : __DIR__"houtang1",
                "south" : __DIR__"wuchang1",
                "north" : __DIR__"liangong",
        ]));

	set("coor/x", -2750);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}