// shuzhi.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(GRN"小树枝"NOR, ({ "shu zhi"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根小树枝。\n");
		set("value", 10);
		set("material", "wood");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_staff(1);
	setup();
}
