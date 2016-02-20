// doufu.c
// Last Modifyed by Winder on Dec. 24 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("麻婆豆腐", ({"doufu", "dou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这就是成都出名的小吃麻婆豆腐，北方的客官可得小心了。\n");
		set("unit", "块");
		set("value", 40);
		set("food_remaining", 1);
		set("food_supply", 50);
	}
}

