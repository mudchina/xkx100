// qin.c

#include <weapon.h>
inherit HAMMER;
void create()
{
	set_name("古木琴", ({ "gumu qin", "qin" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把外表古色古香，但是内包精铁的六弦琴。\n");
		set("value", 3);
		set("material", "iron");
	}

	init_hammer(16);
	setup();
}
