// qingfengding.c
 
#include <weapon.h>
inherit DAGGER;
 
void create()
{
	set_name("青蜂钉", ({ "qingfeng ding", "qingfeng", "ding" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "精铁打制的钉状暗器。\n");
		set("unit", "把");
		set("value", 0);
		set("damage", 5);	//Here the damage=int_throwing, added by King
	}
	init_dagger(5);
	setup();
}


