// chanfang2.c 禅房
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long", @LONG
这里是全真弟子修身养性、打熬气力的地方。为了方便练功，桌
椅都没有摆放，仅仅在地下丢了几个小蒲团。
LONG
        );
        set("exits", ([
                "east" : __DIR__"chanfang3",
                "west" : __DIR__"chanfang1",
                "south" : __DIR__"liangong",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2740);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}