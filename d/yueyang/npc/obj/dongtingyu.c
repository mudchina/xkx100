// dongtingyu.c 洞庭鱼

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(RED"洞庭鱼"NOR, ({"dongting yu", "fish"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一盆烹调得十分美味的洞庭鱼。\n");
		set("unit", "盆");
		set("value", 500);
		set("food_remaining", 10);
		set("food_supply", 20);
	}
}
