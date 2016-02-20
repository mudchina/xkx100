#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"松子"HIR"武昌鱼"NOR, ({"wuchang yu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是“四季美饭庄”的一道名菜，用新鲜武昌鱼烹制而成，香喷喷地冒着热气。\n");
                set("unit", "盘");
                set("value", 800);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
}

