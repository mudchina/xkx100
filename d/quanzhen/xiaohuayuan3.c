// xiaohuayuan3.c 小花园
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小花园");
        set("long", @LONG
这里是重阳观里的小花园，种植着一些叫不出名字来的花木，
园角砌着一座假山，假山下是一潭小小的金鱼池，池水清澈见底，
你看见有数条红色的金鱼在里面悠哉游哉地游来游去。几个道童正
在这里嬉戏着。
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "west" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/daotong" : random(2),
        ]));

	set("coor/x", -2710);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}