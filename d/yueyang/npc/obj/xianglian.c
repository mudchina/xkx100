// xiangliangeng.c 湘莲羹

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY"湘莲羹"NOR, ({"xianglian geng", "geng"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一碗用湖南洞庭湖的莲子熬的羹汤。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 10);
	}
}
