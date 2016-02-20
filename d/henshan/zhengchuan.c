// Room: /d/henshan/zhengchuan.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "正川门");
        set("long", @LONG
正川门是南岳大庙的第三进。院内是玄德宗殿，关圣殿，观音阁等
楼宇。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"kuixingge",
           "north"  : __DIR__"yubeiting",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1170);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
