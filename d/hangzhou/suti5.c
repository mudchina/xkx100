// suti5.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "苏堤");
        set("long", @LONG
每当盛夏，游客到此纷纷寻荫小息，堤上绿树交柯，鸣蝉噪鼓。
北边是望山桥，南面锁澜桥。
LONG);
        set("exits", ([
            "north"     : __DIR__"suti4",
            "south"     : __DIR__"suti6",
        ]));
        set("outdoors", "xihu");
        set("no_clean_up", 0);
	set("coor/x", 4110);
	set("coor/y", -1430);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
