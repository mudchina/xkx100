// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","针叶林");
       set("long", "这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一
层松针。西北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是
绿树成荫。往东南走便是大草原，有辛勤的哈萨克族人在那里放牧。\n");

        set("exits", ([
             "south" : __DIR__"senlin1",
             "north" : __DIR__"senlin"+(1+random(4)),               
             "west"  : __DIR__"senlin"+(1+random(4)),               
             "east"  : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("objects", ([
                         __DIR__"npc/bird" : 1,
        ]));

        set("outdoors", "hasake");

        setup();
       replace_program(ROOM);
}