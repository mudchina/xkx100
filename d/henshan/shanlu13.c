// Room: /d/henshan/shanlu13.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。东北方就是南天门了，高高矗立在西北方的就是衡
山五峰之一的芙蓉峰。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northeast"  : __DIR__"nantian",
           "southeast"  : __DIR__"shanlu5",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -330);
	set("coor/y", -1030);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
