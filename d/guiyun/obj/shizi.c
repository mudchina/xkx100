// Obj: /d/guiyun/obj/shizi.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
#include <weapon.h>

// inherit COMBINED_ITEM;
inherit THROWING;

void create()
{
	set_name("石子", ({ "shizi", "shi" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一堆普普通通的碎石子。\n");               
		set("unit", "堆");
		set("value", 1);
		set("base_value", 0);
		set("base_unit", "颗");
		set("base_weight", 12);
	}
	set_amount(random(70) + 81);
	init_throwing(15);
}

