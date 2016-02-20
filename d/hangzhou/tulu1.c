// tulu1.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
路旁一条小溪。溪水哗哗地流着，不时有鱼儿(fish)跃出水面。
溪旁几个男孩正低着头专心在钓鱼。
LONG);
        set("exits", ([
            "southwest"     : __DIR__"shanlu5",
            "northeast"     : __DIR__"maojiabu",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 2,
        ]));
        set("item_desc", ([
            "fish" : "“哗”一条大鱼跃水而出，“噗”的一声又掉回水里。溅得男孩一身水。\n",
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 2680);
	set("coor/y", -1550);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
