
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "花雕醉鸡" NOR, ({"hdzuiji"}));
        set_weight(2500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "酒香扑鼻的一只花雕醉鸡。\n");
                set("unit", "只");
                set("value", 50);
                set("food_remaining", 10);
                set("food_supply", 20);
                set("cook_msg", "
$N将鸡洗净除内脏，斩去鸡头鸡脚。然后煮沸清水，放下姜片、
葱段、八角，待水再度沸起，放鸡入水中浸煮至熟为为止。再将
鸡取出待冷，鸡汤盛入大汤盅内，加入调味料及同份量的冻开水
拌匀，将花雕酒加入，成为酒卤。最后将鸡件取出斩成小块，排
放上碟，淋上酒卤。\n\n"
		);                
        }
}
