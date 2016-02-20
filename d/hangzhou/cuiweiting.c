// cuiweiting.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "翠微亭");
        set("long", @LONG
翠微亭建在飞来峰的半山间，是名将韩世忠为纪念岳飞而建的。
岳飞有“经年尘土满征衣，特特寻芳上翠微”的诗句，故亭名“翠微”。
西边是下山的路。
LONG);
        set("exits", ([
                "westdown"  : __DIR__"qinglindong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
	set("coor/x", 2520);
	set("coor/y", -1600);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
