
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"麻婆豆腐"NOR, ({"mpdoufu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗色深味厚，麻辣烫咸的麻婆豆腐。\n");
                set("unit", "碗");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N把炒锅置中火上，下菜油烧至五成熟时下肉馅，肉炒干水气后，下豆瓣，
炒出香味，放盐，酱油，同时掺汤，下豆腐。豆腐下锅后烧约三分钟下葱，
葱一熟，就用水淀粉勾芡，起锅装碗，菜面上撒上花椒面。\n\n"
		);
        }
}
