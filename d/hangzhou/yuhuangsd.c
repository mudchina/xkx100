// yuhuangsd.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "玉皇山顶");
        set("long", @LONG
登上玉皇山，俯瞰山下，可以看到“八卦田”。据说这是皇帝祭
先农时亲耕的籍田。山顶有福星观，建於唐朝。廊宇旁有天一池和白
石井，并建有望湖亭。东西两边各有一条下山的路。
LONG);
        set("exits", ([
            "eastdown"  : __DIR__"shanlu7",
            "westdown"  : __DIR__"shanlu6",
        ]));
        set("objects", ([
            __DIR__"honghua/yu" : 1,
        ]));
        set("outdoors", "xihu");
	set("coor/x", 4100);
	set("coor/y", -1700);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
