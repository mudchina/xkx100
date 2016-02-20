// swimming-cloth.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("Ó¾¿ã", ({"swimming cloth", "yong ku", "cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ìõ");
		set("value", 4000);
		set("material", "cloth");
		set("armor_prop/armor", 15);
		set("armor_prop/dodge", 5);
		set("armor_prop/spells", 10);
	}
	setup();
}

