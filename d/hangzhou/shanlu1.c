// shanlu1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
一条被人走出来的山路，弯弯曲曲地向上延伸。走在山路上，只
见两旁峰峦秀丽，景色怡人。不时有进香客擦肩而过。南上便到了下
天竺。北下就是大道。
LONG);
        set("exits", ([
                "southup"   : __DIR__"fajingsi",
                "northdown" : __DIR__"road2",
        ]));
        set("outdoors", "hangzhou");
        set("no_clean_up", 0);
	set("coor/x", 2600);
	set("coor/y", -1410);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
