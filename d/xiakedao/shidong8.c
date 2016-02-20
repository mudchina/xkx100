// Room: /xiakedao/shidong8.c
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG
这是一个石洞，四周是光滑的石壁，石洞内干干净净，一尘不
染。两旁点着火把，非常明亮。南面有一扇虚掩的石门(door)。
LONG );
        set("exits", ([
                "east" : __DIR__"shidong7",
               "south" : __DIR__"road5"
        ]));
        set("item_desc", ([
                "door" : "这是一扇极厚的石门。\n"
        ]));
        set("objects", ([
                __DIR__"npc/dizi" : 1,
        ]));
	set("coor/x", -3110);
	set("coor/y", -22100);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("di zi", environment(me))) &&
                dir == "south")
                return notify_fail("侠客岛弟子拦住你说：这是本岛禁地，请回吧。\n");
        return ::valid_leave(me, dir);
}