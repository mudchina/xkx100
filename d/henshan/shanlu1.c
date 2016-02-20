// Room: /d/henshan/shanlu1.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"beimen",
           "northwest"  : __DIR__"shanlu2",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1100);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
