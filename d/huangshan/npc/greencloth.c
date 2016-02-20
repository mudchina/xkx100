
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("´Ö²¼°×ÅÛ", ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
	setup();
}
