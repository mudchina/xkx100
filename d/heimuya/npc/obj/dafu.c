// dafu.c

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name("大斧", ({"da fu", "axe","fu"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄十分锋利的大斧。\n");
		set("value", 100);
		set("material", "bamboo");
		set("wield_msg", "$N回手从身后抽出一柄大斧。\n");
		set("unwield_msg", "$N手往后一别，把大斧插在后腰上。\n");
	}
	init_axe(80);
	setup();
}
