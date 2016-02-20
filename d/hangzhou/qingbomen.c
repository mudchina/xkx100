// qingbomen.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "清波门");
        set("long", @LONG
园门口有一大门楼，大匾上刻着“清波门”。门楼下站着几个嬉
嬉哈哈的少女，惹人坠步相观。再往西就进了聚景园，往东便回到大
路。
LONG);
        set("exits", ([
            "east"   : __DIR__"road14",
            "west"   : __DIR__"jujingyuan",
        ]));
        set("objects", ([
            __DIR__"npc/girl" : 2,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4130);
	set("coor/y", -1490);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
