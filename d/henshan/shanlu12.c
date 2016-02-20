// Room: /d/henshan/shanlu12.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。西边上山的路。东边隐隐听到水响。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"    : __DIR__"shanlu11",
           "eastup"  : __DIR__"shuiliandong",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -290);
	set("coor/y", -1080);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
