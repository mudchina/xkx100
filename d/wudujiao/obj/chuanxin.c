// chuanxin.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
               set_name("穿心莲", ({"chuanxin lian","lian" }));

                set("unit", "朵");
                set("long", "这是一朵粉红色的莲花。\n");
                set("value", 500);
//            set("no_drop", "这样东西不能离开你。\n");
              set_weight(50);


        setup();
}

