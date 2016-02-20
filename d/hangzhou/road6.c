// road6.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西
湖。大道延伸向东西两边。南边则通往苏堤。北边是岳王庙。
LONG);
        set("exits", ([
            "north"     : __DIR__"yuelang",
            "south"     : __DIR__"suti1",
            "west"      : __DIR__"road5",
            "east"      : __DIR__"road7",
        ]));
        set("objects" , ([
            __DIR__"npc/liumang" :4,
            __DIR__"npc/liumangtou" :1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4080);
	set("coor/y", -1440);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
