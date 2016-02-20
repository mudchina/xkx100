// biandan.c

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(GRN"扁担"NOR, ({ "bian dan", "dan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一条挑担的扁担。\n");
		set("value", 100);
		set("material", "wood");
		set("wield_msg", "$N拿出一条$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(1);
	setup();
}
