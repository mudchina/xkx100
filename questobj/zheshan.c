// zheshan.c

#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name(YEL"油纸折扇"NOR, ({ "zhe shan", "shan" }));
	set_weight(12000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "这是一对用镔铁为骨的油纸折扇。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声从怀中掏出一只$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n揣回怀里。\n");
	}
	setup();
}

