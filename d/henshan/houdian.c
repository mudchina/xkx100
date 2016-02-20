// Room: /d/henshan/houdian.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "后殿");
        set("long", @LONG
后殿是南岳大庙的第八进，也是南岳大帝的寝宫。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "south"  : __DIR__"dadian",
           "north"  : __DIR__"beimen",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1120);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
