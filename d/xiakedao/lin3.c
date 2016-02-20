// /d/xiakedao/lin3.c
// Modified by Zeratul Jan 11 2001

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林，好象被人设计了一种阵，一走进来，你仿佛迷失了方向。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"lin2",
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __DIR__"lin4",
                "northeast" : __FILE__,
        ]));
        set("objects", ([
            __DIR__"npc/zhangsan" : 1,
            __DIR__"npc/lisi" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
