// feidao.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name("飞刀", ({ "fei dao", "feidao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "特制的飞刀，每只都磨得十分锋锐。\n");
		set("unit", "把");
		set("value", 0);
		set("base_unit", "把");
		set("base_weight", 1);
		set("base_value", 0);
		set("damage", 5);	//Here the damage=int_throwing, added by King
	}
	set_amount(20);
	init_throwing(25);
	setup();
}
