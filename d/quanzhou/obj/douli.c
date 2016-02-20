// douli.c
// Last Modified by winder on May. 25 2001

#include <armor.h>
inherit HEAD;

void create()
{
	set_name("∂∑Û“", ({ "dou li", "douli" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∂•");
		set("material", "cloth");
		set("value", 150);
		set("armor_prop/armor", 2);
	}
	setup();
}

