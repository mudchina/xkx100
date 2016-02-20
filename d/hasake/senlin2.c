// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	int a1,a2,a3,a4;
	a1 = 1+random(4);
	a2 = 1+random(4);
	a3 = 1+random(4);
	if (a1 != 3 && a2!=3 && a3!=3) a4=3;
	else a4 = 1+random(4);
       set("short","针叶林");
       set("long", @LONG
这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一
层松针。北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是绿
树成荫。往南走便是大草原，有辛勤的哈萨克族人在那里放牧。你走着走
着，竟然迷失了道路。
LONG);
        set("exits", ([
             "east"  : __DIR__"senlin"+a1,
             "west"  : __DIR__"senlin"+a2,
             "south" : __DIR__"senlin"+a3,
             "north" : __DIR__"senlin"+a4,        
        ]));
        
        set("objects", ([
                         __DIR__"npc/huilang" : 1,
        ]));

        set("outdoors", "hasake");
        setup();           
}

