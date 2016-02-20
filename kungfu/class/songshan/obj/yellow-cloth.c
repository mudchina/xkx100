
// yellow-cloth.c
// Ати╫╨у╩феш

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(YEL"╨у╩феш"NOR, ({ "yellow cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "╪Ч");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 5);
	}
	setup();
}

