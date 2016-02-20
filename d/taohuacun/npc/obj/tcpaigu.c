#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED "糖醋排骨" NOR, ({"tcpaigu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘酸甜可口的糖醋排骨。\n");
		set("unit", "盘");
		set("value", 15);
		set("food_remaining", 5);
		set("food_supply", 20);
		set("cook_msg", "
$N把小排切块加调味料拌匀，腌渍入味，再把洋葱、胡萝卜、小
黄瓜滚刀切块。小排入油锅炸成金黄色取出。然后在乾净锅中入
油半大匙，爆香蒜屑、洋葱，再加入胡萝卜、小黄瓜、炸好的小
排，拌入调味料。\n\n"
		);		
	}
}