// Room: /d/henshan/chidifeng.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "赤帝峰");
        set("long", @LONG
相传祝融能 "以火施化" ，是黄帝的 "火正官" ，并主管南方的事
务，死后葬于此，故名赤帝峰。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanlu2",
           "eastdown"   : __DIR__"shanlu11",
           "northdown"  : __DIR__"shanlu3",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1080);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
