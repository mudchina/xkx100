// qianrizui.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("千日醉", ({"qianri zui","zui" }));

                set("unit", "颗");
                set("long", "这是一颗核桃大小的果实，散发着一股浓郁的酒香。\n");
                set("value", 200);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

