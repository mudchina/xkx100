// shaobing.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(YEL"ÈâÄ©ÉÕ±ý"NOR, ({"roumo shaobing", "bing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö»");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 5);
	}
}

