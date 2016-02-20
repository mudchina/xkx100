// Room: /d/wudujiao/minju10.c

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这是一个用篱笆围成的简易院落，远处种着几畦蔬菜。院子
中间一棵高大的柿树上结满了鲜红的果实，旁边的地上盖着一张
厚厚的草席。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "north" : __DIR__"minju6",
        ]));
        set("objects", ([
                  __DIR__"npc/xuetong": 3,
        ]));
        set("item_desc", ([
                "草席" : "\n一张厚厚的草席盖在洞口，下面似乎是一个地窖。\n" ,
        ]));
	set("coor/x", -44940);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_move", "pull");
}
int do_move(string arg)
{
        object me,hole;
        string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
        if( arg=="草席" ) {
            message_vision("\n$N掀开盖在洞口的草席走了下去。\n", this_player());
            me->move(__DIR__"dijiao");
            message_vision("\n盖在洞口的草席一掀，$N从上面走了下来。\n",me);
        }
        else {
            message_vision("\n$N双手在空中比划了几下，但似乎什么也没抓住。\n", this_player());
        }
        return 1;
}