// datang3.c 大堂三进
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大堂三进");
        set("long", @LONG
这里是大堂的第三进，是全真教弟子议事的地方。全真教祖师王
重阳王真人最近闭关修炼，教内的俗事一般都交给大弟子马钰来处理。
遇有事时，马真人便会召集六位师弟师妹，包括三代弟子中的部分大
弟子来到此地议事。
LONG
        );
        set("exits", ([
                "east" : __DIR__"laojundian",
                "south" : __DIR__"nairongdian",
                "west" : __DIR__"datang2",
                "north" : __DIR__"guozhendian",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/fang" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}