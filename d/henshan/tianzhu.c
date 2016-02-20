// Room: /d/henshan/tianzhu.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "天柱峰");
        set("long", @LONG
你爬上衡山五峰之一的天柱峰，四望群山缥缈云雾中，每每天阴地
湿时候，这里就是天柱云气的所在了。 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"   : __DIR__"shanlu10",
           "eastdown"   : __DIR__"shanlu7",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -350);
	set("coor/y", -1050);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
