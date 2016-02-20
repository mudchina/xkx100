// road19.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。大道伸向东和西南两边，往北是另一条大道。
LONG);
        set("exits", ([
            "north"     : __DIR__"dadao3",
            "southwest" : __DIR__"road18",
            "east"      : __DIR__"road20",
        ]));
        set("objects" , ([
            __DIR__"npc/dao-ke"  :1,
            __DIR__"npc/longjun" :1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4100);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
