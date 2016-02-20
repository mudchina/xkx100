#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"龙井虾仁"NOR, ({"ljxiaren"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "酽酽浓浓的一盘龙井虾仁。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N将河虾洗净，挤出虾仁，用蛋清、精盐、湿淀粉浆好；
取龙井新茶少许，用沸水沏泡；浆好的虾仁用四成热的大油
滑熟，再烹上茶叶、茶汁、绍酒翻炒。\n\n"
		);                
        }
}
