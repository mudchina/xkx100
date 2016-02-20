// caolianfang.c 操练房
// Modified by Marz 03/27/96

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "操练房");
        set("long", @LONG
这是二楼操练房上，四面八方都是打斗声，武当弟子来去匆匆。
LONG );
        set("exits", ([
                "south"     : __DIR__"caolian1",
                "north"     : __DIR__"caolian2",
                "eastdown"  : __DIR__"xilang"
        ]));
	set("no_clean_up", 0);
	set("coor/x", -2070);
	set("coor/y", -920);
	set("coor/z", 100);
	setup();
}
