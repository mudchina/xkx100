// yuhuangsj.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "玉皇山脚");
        set("long", @LONG
只见往上的山路曲折蜿延。山路旁有一座小六角亭，几个游人正
在亭里歇脚。东北边是一条青石大道，往西是上山的路。
LONG);
        set("exits", ([
            "northeast" : __DIR__"road15",
            "westup"    : __DIR__"shanlu7",
        ]));
        set("objects", ([
            __DIR__"npc/honghua1" : 2,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4120);
	set("coor/y", -1700);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
