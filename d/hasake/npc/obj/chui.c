// 针

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;


void create()
{
	set_name("流星锤", ({ "liuxing chui", "chui", "hammer" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "一柄精铁制的流星锤。\n");
		set("value", 1000);
                set("weapon_prop/parry", 1);
                       set("poisoned", "bing_poison");
		set("material", "steel");
                         set("poison_number", 300);		
	}
	init_hammer(40);
	setup();
}