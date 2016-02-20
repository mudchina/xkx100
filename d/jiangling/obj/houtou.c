#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIB"猴头"HIM"芙蓉"NOR, ({"houtou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是“四季美饭庄”的一道名菜，香喷喷地冒着热气。\n");
                set("unit", "盘");
                set("value", 1000);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

