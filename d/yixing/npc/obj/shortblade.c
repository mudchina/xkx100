// shortblade.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("短刀", ({ "short blade", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("value", 0);
                set("base_unit", "柄");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "iron");
		set("unit", "把");
		set("long", "这是一捆飞刀。\n");
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	set_amount(18);
	init_throwing(25);
	setup();
}
