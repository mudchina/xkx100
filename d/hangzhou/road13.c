// road13.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，
一片太平热闹景象。街东边有一家客店。
LONG);
        set("exits", ([
            "north"     : __DIR__"road12",
            "southwest" : __DIR__"road14",
            "east"      : __DIR__"kedian",
        ]));
        set("objects", ([
            __DIR__"npc/zhang": 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4150);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
