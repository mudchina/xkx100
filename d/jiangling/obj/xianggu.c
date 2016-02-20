#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLK"香菇"HIY"烧板栗"NOR, ({"xianggu banli"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是“四季美饭庄”的一道名菜，香喷喷地冒着热气。\n");
                set("unit", "盘");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 50);
        }
}

