
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIW "栗子扒白菜" NOR, ({"lizibaicai"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘栗子扒白菜。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N将津白洗净切大段,栗子去壳用清水煮至略透,滤干水份。
再将冬菇浸软洗净去蒂。烧热油约两汤匙,将津白放下炒软,
加入调味料、冬菇、栗子、金笋片文火煮至熟透。用少许
生粉水打芡。\n\n"
		);                
        }
}
