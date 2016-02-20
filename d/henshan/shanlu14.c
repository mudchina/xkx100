// Room: /d/henshan/shanlu14.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
你走在衡山山路上，四望山峰错落，林壑幽深，溪泉飞瀑，云雾缭
绕，不觉心胸大快。山路转过芙蓉峰，西面远远看到藏经阁，东南方向
通往南天门。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"       : __DIR__"cangjingdian",
           "southeast"  : __DIR__"nantian",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanbei" : random(2),
        ]));
        set("outdoors", "henshan");
	set("coor/x", -330);
	set("coor/y", -1010);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
