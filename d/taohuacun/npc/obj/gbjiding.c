
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "宫爆鸡丁" NOR, ({"gbjiding"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗鲜香细嫩，辣而不爆，略带甜酸的宫爆鸡丁。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N取嫩公鸡脯肉，穿上花刀切成方丁，用酱油、精盐、
湿淀粉上浆，放入干红辣椒、花椒油中炒散，加入葱、
姜、蒜、熟花生米，再烹上糖、醋、 盐、味精、肉
清汤和成的芡汁。\n\n"
		);                
        }
}
