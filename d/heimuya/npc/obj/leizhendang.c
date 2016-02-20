// leizhendang.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("雷震挡", ({"leizhen dang", "staff"}));
	set_weight(8000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "一杆十分沉重的雷震挡。\n");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N回手从身后抽出一杆雷震挡。\n");
		set("unwield_msg", "$N手往后一扣，把雷震挡放在身后。\n");
	}
	init_staff(50);
	setup();
}
