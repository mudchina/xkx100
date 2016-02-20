// duanqiao.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "断桥");
        set("long", @LONG
断桥正好在外湖和里湖的分水点上。这里亭轩错落，掩映在绿树佳荫之下。
“山明水秀轩扉启，落日渔歌过里湖”，就是描述这里傍晚的景色。在断桥
上可浏览环湖诸山和湖中诸岛的风光。每当雪後，站在桥头，只见一切都被
覆上白雪，玉琢银镂的湖山风貌就是西湖十景之一的“断桥残雪”。民间神
话“白蛇传”中的白娘娘和许仙就在这里相会的。
    过桥往西走便是白堤了。东北边可通往青石大道。
LONG);
        set("exits", ([
            "northeast" : __DIR__"road9",
            "west"      : __DIR__"baiti",
        ]));
        set("objects", ([
            __DIR__"npc/poorman" : 1,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xihu");
	set("coor/x", 4140);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
