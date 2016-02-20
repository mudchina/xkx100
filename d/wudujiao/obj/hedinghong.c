// hedinghong.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("鹤顶红", ({"heding hong","hong" }));

                set("unit", "瓶");
                set("long", "这是一瓶剧毒的粉末。\n");
                set("value", 100);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

