#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"龙凤配"NOR, ({"longfeng"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "相传为三国刘备招亲而制作的庆筵名菜。鳝作龙，鸡作凤，形态逼真，味道鲜美。\n");
                set("unit", "碗");
                set("value", 500);
                set("food_remaining", 10);
                set("food_supply", 100);
        }
}

