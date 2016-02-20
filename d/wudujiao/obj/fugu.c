// fugu.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("腐骨草", ({"fugu cao","cao" }));

                set("unit", "株");
                set("long", "这是一株普通的小草，叶面发出一股难闻的臭气。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

