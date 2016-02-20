// liulangqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "柳浪桥");
        set("long", @LONG
每当春至，站在桥上，沿湖垂柳在风中摇曳如翠浪翻空，黄莺在
枝头迎春嬉戏，鸣声婉转，故得名“浪桥闻莺”。
LONG);
        set("exits", ([
            "southwest" : __DIR__"jujingyuan",
        ]));
        set("objects", ([
            __DIR__"npc/maque" : 2,
            __DIR__"npc/wuya" : 1,
        ]));
        set("outdoors", "xihu");
//        set("no_clean_up", 0);
	set("coor/x", 4130);
	set("coor/y", -1480);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
