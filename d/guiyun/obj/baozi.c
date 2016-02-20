// Obj: /d/guiyun/obj/baozi.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("小笼包", ({"baozi"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟放凉了的包子。\n");
		set("unit", "碟");
		set("value", 0);
		set("food_remaining", 5);
		set("food_supply", 30);
	}
}
