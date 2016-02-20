// shuyuan.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "凤池书院");
        set("long", @LONG
书院正中有一匾“凤池书院”。书院里坐着两位老者，他们正在
吟诗作对。他们身旁的桌上铺着宣纸和笔墨。
LONG);
        set("exits", ([
            "west"      : __DIR__"road12",
        ]));
        set("no_clean_up", 0);
	set("coor/x", 4160);
	set("coor/y", -1470);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}