// Room: /d/henshan/fangguangsi.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "方广寺");
        set("long", @LONG
方广寺在莲花峰下。莲花峰有八个山头，犹如金莲瓣瓣，方广寺就
建在这莲花中心的一片平地上。深邃幽雅，有 "不游方广寺，不知南岳
之深" 之说，故 "方广寺之深" 为衡山大四绝之一。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southdown"  : __DIR__"shanjian",
           "eastup"     : __DIR__"shanlu10",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -370);
	set("coor/y", -1050);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
