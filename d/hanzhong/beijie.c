// beijie.c 北街
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "北街");
        set("long", @LONG
北街是汉中镇最繁华的街道，每逢初一十五，还要在这里举行
些庙会之类的聚会。街北面是一家酒楼，楼前挂着一条蓝幅，上面
写了个大大的‘酒’字。西面是一户人家。几个小孩在街上笑着闹
着互相追逐。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "south" : __DIR__"zhongxin",
                "north" : __DIR__"jiulou1",
                "west"  : __DIR__"minju1",
        ]));
        set("objects", ([
                __DIR__"npc/kid" : 3,
        ]));

	set("coor/x", -3150);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
