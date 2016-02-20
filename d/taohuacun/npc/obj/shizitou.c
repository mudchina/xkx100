
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC "清炖蟹粉狮子头" NOR, ({"shizitou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗肥嫩异常，入口即化的清炖蟹粉狮子头。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N先用猪肋条肉，分别切成石 榴粒状，再混合起来粗略地
[赞刂]一[赞刂]，加上葱姜汁、蟹肉、虾子、精盐、 绍酒、
干淀粉调拌均匀，直至“上劲”。用熟猪油擦抹沙锅底，将
青菜叶排在 底中，放入猪肉汤烧沸，然后将拌均匀的肉馅
放入手掌中，双手来回滚动团成 光滑的肉圆，逐个排在菜心
上，每个再嵌上蟹黄，盖上青菜叶，烧沸后，移在微火上焖
约一个时辰，掀去青菜叶。\n\n"
		);                
        }
}
