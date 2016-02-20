#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC"冬瓜鳖裙羹"NOR, ({"donggua"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是“四季美饭庄”的一道名菜，选用肥美的雄鳖裙边和嫩冬瓜，再加鸡汤，清炖而成。\n");
                set("unit", "碗");
                set("value", 500);
                set("food_remaining", 1);
                set("food_supply", 100);
        }
}

