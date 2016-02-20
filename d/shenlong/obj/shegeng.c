// shegeng.c Éß¸ş
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("Éß¸ş", ({"shegeng", "geng"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»ÍëÅ¨Å¨µÄÉß¸ş¡£¡¸ÍÛ!¡¹\n");
		set("unit", "Íë");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
