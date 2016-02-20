// Room: /d/wudujiao/tree.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "榕树上");
        set("long", @LONG
这里是大树的顶端，四周是浓密的枝叶和湿漉漉的苔藓。一阵
微风吹来，树叶发出唰啦啦的声音。从上面望下去，你只觉得一阵
眼晕，心想还是赶快下去吧。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
        ]));
        set("objects", ([
                  __DIR__"obj/xiang": 1,
        ]));

        set("coor/x", -44920);
	set("coor/y", -81060);
	set("coor/z", 50);
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
        if( (!arg) ||!((arg == "tree") || (arg == "down")))
                return notify_fail("你要爬什么？\n");
                message_vision("$N攀着榕树的枝杈慢慢的爬了下去。\n\n",me);
        ob = load_object(__DIR__"nanyuan");
        ob = find_object(__DIR__"nanyuan");
        message("vision", me->query("name")+"从榕树上面爬了下来。\n", ob);
        me->move(__DIR__"nanyuan");
        return 1;
}

