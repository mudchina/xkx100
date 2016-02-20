// Room: /d/wudujiao/wandu3.c

inherit ROOM;
#include <ansi.h>
string* npcs = ({
        __DIR__"npc/wandu1",
        __DIR__"npc/wandu2",
        __DIR__"npc/wandu3",
        __DIR__"npc/wandu4",
        __DIR__"npc/wandu5",
});

void create()
{
        set("short", "万毒窟");
        set("long", @LONG
这里是山洞内部的支洞，这里已经没有一丝光线了，黑洞洞的
什么也看不见。洞内岩壁上好象生着几株不知名的小草。身旁传来
一阵“咝咝”的声音。
LONG
        );

        set("exits", ([
                "north" : __DIR__"wandu2",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

	set("coor/x", -44970);
	set("coor/y", -81110);
	set("coor/z", 0);
	setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{

        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "岩壁") || (arg == "洞壁")))
                return notify_fail("你要爬什么？\n");
                message_vision(HIC"$N攀着岩壁上突出的石笋艰难的爬了上去。\n\n"NOR,me);
        ob = load_object(__DIR__"dongxue");
        ob = find_object(__DIR__"dongxue");
        message("vision", me->query("name")+"从下面爬了上来。\n", ob);
        me->move(__DIR__"dongxue");
        return 1;
}