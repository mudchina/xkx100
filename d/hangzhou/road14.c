// road14.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "青石大道");
        set("long", @LONG
沿湖大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，
一片太平热闹景象。西边有一花园，游人进进出出，十分热闹。东边
是名医胡庆余开的药铺。
LONG);
        set("exits", ([
            "northeast" : __DIR__"road13",
            "southwest" : __DIR__"road15",
            "east"      : __DIR__"yaodian",
            "west"      : __DIR__"qingbomen",
        ]));
        set("objects", ([
            __DIR__"honghua/wen" :1,
            __DIR__"honghua/luo" :1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4140);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
