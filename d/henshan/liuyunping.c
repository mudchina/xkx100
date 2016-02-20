// Room: /d/henshan/liuyunping.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "流云坪");
        set("long", @LONG
每逢雨霁，在后山深壑中升腾起来的云山雾海，涌过南天门山脊，
向前山倾泻，直如银河飞泻，蔚为壮观，这就是南天门的流云奇景。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westdown"  : __DIR__"nantian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -1020);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
