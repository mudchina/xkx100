// duanchang.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("断肠草", ({"duanchang cao","cao" }));

                set("unit", "株");
                set("long", "这是一株闪烁着磷光的小草。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

