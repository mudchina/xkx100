// chaofu.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("朝服", ({ "chao fu", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件补服，是大臣上朝时穿的。\n");
		set("unit", "件");
		set("value", 60);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
	}
	setup();
}
