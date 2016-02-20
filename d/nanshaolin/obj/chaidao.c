// Obj: /d/nanshaolin/obj/chaidao.c
// Last Modified by winder on May. 29 2001

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name("柴刀",({"chai dao","dao"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","把");
		set("value",50);
		set("material","black_steel");
		set("long","这是一柄用于砍柴的柴刀，看来用的年代已十分久远。\n");
		set("wield_msg","$N拿出一把柴刀握在手里。\n");
		set("unwield_msg","$N将柴刀放下。\n");
	}
	init_blade(10);
	setup();
}

