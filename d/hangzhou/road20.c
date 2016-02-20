// road20.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。大道伸向东西两边，往北是苏堤。
LONG);
        set("exits", ([
            "north"     : __DIR__"suti7",
            "west"      : __DIR__"road19",
            "east"      : __DIR__"road16",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4110);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
