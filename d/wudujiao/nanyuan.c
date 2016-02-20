// Room: /d/wudujiao/nanyuan.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "南院");
        set("long", @LONG
这里是南跨院，院子里有棵很大的榕树，将天空大部遮住，院子里静
悄悄的，只有几只高大的藏獒在树下来回踱步。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"yaoshi",
                "south" : __DIR__"liandu",
                "west" : __DIR__"xiangfang",
                "north" : __DIR__"lianwu",
        ]));
        set("objects", ([
                  __DIR__"npc/zangao": 2,
        ]));

	set("coor/x", -44920);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
}

void init()
{
       add_action("do_climb","climb");
}
int do_climb(string arg)
{

        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "tree") || (arg == "up")))
                return notify_fail("你要爬什么？\n");
                message_vision("$P撮了撮手，攀着榕树的枝杈三下两下就爬了上去。\n
\n",me);
        ob = load_object(__DIR__"tree");
        ob = find_object(__DIR__"tree");
        message("vision", me->query("name")+"从下面爬了上来。\n", ob);
        me->move(__DIR__"tree");
        return 1;
}