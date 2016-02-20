// qiancenggao.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(HIG"千层糕"NOR, ({"qianceng gao", "gao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这千层糕是一层面粉一层蜜糖猪油做成，更有桂花香气，既松且甜。\n");
		set("unit", "块");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}

