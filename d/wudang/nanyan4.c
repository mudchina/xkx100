// Room: nanyan4.c 南岩宫迷宫
// Oct. 6 1997

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        object ob1,ob2;
        set("short", "南岩迷宫");
        set("long", @LONG
你现在南岩宫地下密室中，高挂的腕粗的油烛照得满堂透亮。但周
围静谧如夜，除了烛火闪烁的风声外，你什么也听不见。这里只有你一
个人。你脚下缓缓而动，全神戒备，没有人能帮助你。
LONG
        );
        set("exits", ([
            "east"      : __DIR__"nanyan1",
            "south"     : __DIR__"nanyan2",
            "west"      : __DIR__"nanyan3",
            "north"     : __DIR__"nanyan4",
            "southeast" : __DIR__"nanyan1",
            "southwest" : __DIR__"nanyan2",
            "northeast" : __DIR__"nanyan3",
            "northwest" : __DIR__"nanyan0",
        ]));
        set("objects", ([
                __DIR__"obj/table" : 1,
                "/clone/misc/corpse" : 1,
                "/clone/money/gold": 1,
        ]) );
//        set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -960);
	set("coor/z", 70);
	setup();
        replace_program(ROOM);
        ob1 = present("table", this_object());
        ob2 = present("corpse", this_object());
        ob2->move(ob1);
        ob2 = present("gold", this_object());
        ob2->move(ob1);
}
