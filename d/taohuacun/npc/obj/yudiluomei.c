#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIM "玉笛谁家听落梅" NOR, ({"yudiluomei"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香气浓郁的炙牛肉条，每条牛肉都是由四条小肉条拼成。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$N取大小相等的羊羔坐臀、小猪耳朵、小牛腰子、獐腿肉加免肉，
分别反复捶打，至软烂，去其筯膜，取四样肉条小心翼翼地合拼
成玉笛状，置于小火上烤。\n\n");                
        }
}
