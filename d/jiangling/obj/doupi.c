#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"豆皮"NOR, ({"doupi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是武汉人爱吃的一种小吃。\n");
                set("unit", "碗");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 50);
        }
}

