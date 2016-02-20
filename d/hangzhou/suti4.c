// suti4.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "苏堤");
        set("long", @LONG
春晓，漫步林荫道上，烟柳笼纱，雀鸟欢鸣，一片生机。苏堤春
晓被列为西湖十景之首，果然名不虚传。北边是压堤桥，南面是望山
桥。东面一片梅林，林后似乎有座院落，但看不真切。
LONG);
        set("exits", ([
            "north"     : __DIR__"suti3",
            "south"     : __DIR__"suti5",
        ]));
        set("objects", ([
            __DIR__"npc/liyuanzhi" : 1,
            __DIR__"npc/wuya" : 1,
            __DIR__"npc/maque" : 2,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4110);
	set("coor/y", -1420);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
