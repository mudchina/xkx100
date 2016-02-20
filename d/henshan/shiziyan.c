// Room: /d/henshan/shiziyan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "狮子岩");
        set("long", @LONG
狮子岩布满奇形怪状的岩石，细究则绝类狮子，腾跃伏吼，各肖其
类。到狮子岩，祝融峰已经在望了。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
