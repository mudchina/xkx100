// dart.c

#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("七寸长的短剑", ({ "short sword", "sword" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "精光四射的短剑，剑长七寸，剑柄两寸。\n");
		set("unit", "把");
		set("base_unit", "把");
		set("base_weight", 40);
		set("value", 5);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
