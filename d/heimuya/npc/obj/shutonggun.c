// shutonggun.c

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name("熟铜棍", ({"shutong gun", "club"}));
	set_weight(2000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分灵便的熟铜棍。\n");
		set("value", 1000);
		set("material", "bamboo");
		set("wield_msg", "$N回手从身后抽出一杆熟铜棍。\n");
		set("unwield_msg", "$N手往后一扣，把熟铜棍放在身后。\n");
	}
	init_club(30);
	setup();
}
