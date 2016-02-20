// zhudao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("破竹刀", ({ "zhu dao", "blade" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把破竹成篾的竹刀。\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N从兜里掏出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放回兜里。\n");
	}
	init_blade(5,0);
	setup();
}
