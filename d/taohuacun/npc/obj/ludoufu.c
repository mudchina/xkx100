
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL "卤豆腐" NOR, ({"ludoufu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘散发着浓香的卤豆腐。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N将黄豆腐完整地放在冷水锅里，盖好锅盖，用旺火煮到豆腐出现
许多小孔。形如蜂窠状时取出。再将猪排用开水川一下，以拔去
血水。然后起净干锅，将豆腐放入，再将猪排放在豆腐上面，加清
汤、酱油、糖、用小温火烧约二十分钟，最后将豆腐取出，切成片。\n\n"
		);                
        }
}
