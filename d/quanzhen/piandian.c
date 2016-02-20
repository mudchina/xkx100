// piandian.c 偏殿
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "偏殿");
        set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不
大，只摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆
景，墙壁上挂着一些字画。
LONG
        );
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/shen" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2790);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}