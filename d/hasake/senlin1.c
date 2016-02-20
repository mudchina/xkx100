// senlin.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
       set("short","针叶林");
       set("long", @LONG
这是极西天山脚下的一片针叶林，林中鸟兽成群，满地铺盖着厚厚一
层松针。北方的一座高耸的山脉便是天山了，山上终年积雪，山下却是绿
树成荫。往南走便是大草原，有辛勤的哈萨克族人在那里放牧。你走着走
着，竟然迷失了道路。
LONG);
        set("exits", ([
             "eastup"  : __DIR__"shanqiu",
             "west"  : "/d/xingxiu/shanjiao",
             "south" : __DIR__"senlin"+(1+random(4)),
             "north" : __DIR__"senlin"+(1+random(4)),               
        ]));
        
        set("outdoors", "hasake");
        setup();            
}
