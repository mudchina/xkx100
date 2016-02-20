// Obj: /d/guiyun/obj/mujian.c
// Last Modified by winder on Jul. 9 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("木剑", ({ "mu jian", "jian" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄用木头削成的剑，可以做击刺之用。\n");
		set("value", 1270);
		set("material", "wood");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(5);
	setup();
}
