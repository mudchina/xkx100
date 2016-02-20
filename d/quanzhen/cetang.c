// cetang.c 侧堂
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "侧堂");
        set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青松山石的盆
景，墙壁上挂着一些字画。
LONG
        );
        set("exits", ([
                "east" : __DIR__"guozhendian",
                "west" : __DIR__"huizhentang",
                "north" : __DIR__"shiweishi",
                "south" : __DIR__"datang2",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/li" : 1,
        ]));

	set("coor/x", -2790);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}