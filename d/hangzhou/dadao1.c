// dadao1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "沿湖大道");
        set("long", @LONG
一条宽敞的大道上却游人稀少。原来这里沿路住着的都是达官贵
人。本来风景秀丽之处，却显的一片萧瑟。路的西边是一座庄园，大
道向南北延伸。
LONG);
        set("exits", ([
            "north"     : __DIR__"road5",
            "south"     : __DIR__"dadao2",
            "west"      : __DIR__"guozhuang",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/baiwei" : random(2),
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4070);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
}
