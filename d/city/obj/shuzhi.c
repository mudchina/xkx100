// shuzhi.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(GRN"大树枝"NOR, ({ "shu zhi"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
        set("long", "这是一根爬山用的树枝。\n");
        set("value", 50);
		set("material", "wood");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(5);
	setup();
}
