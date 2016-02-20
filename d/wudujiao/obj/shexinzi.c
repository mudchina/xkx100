// shexinzi.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("蛇信子", ({"shexin zi","zi" }));

                set("unit", "颗");
                set("long", "这是一颗植物的果实。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

