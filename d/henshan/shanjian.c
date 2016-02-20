// Room: /d/henshan/shanjian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山涧");
        set("long", @LONG
顺山涧漂流而下，沿溪遍布珍稀树木，泉石，林木，花草及峰峦均
极宜人。涧流至崖折叠飞泄而下，声震山谷。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
        set("outdoors", "henshan");
        set("objects", ([
                "/clone/medicine/vegetable/gouzhizi" : random(2),
        ]));
	set("coor/x", -370);
	set("coor/y", -1060);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
