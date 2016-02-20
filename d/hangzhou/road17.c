// road17.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。大道伸向南北两边，往西是虎跑泉，往东是一条山路。
LONG);
        set("exits", ([
            "north"     : __DIR__"road18",
            "south"     : __DIR__"qiantang",
            "west"      : __DIR__"hupaoquan",
            "east"      : __DIR__"yuhuangshan",
        ]));
        set("objects", ([
            __DIR__"npc/tiao-fu" : 1,
            __DIR__"npc/chuyuan" : 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4000);
	set("coor/y", -1700);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
