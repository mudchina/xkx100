// Obj: /d/guiyun/obj/stick.c
// Last Modified by winder on Jul. 9 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("树枝", ({ "shuzhi", "stick" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long","这是一根普通的小树枝，你挥了两下，感觉可以用来击刺敌人。\n");
		set("value", 1);
		set("material", "wood");
		set("wield_msg", "$N拿出一根$n握在手中。\n");
		set("unwield_msg", "$N放下了手中的$n。\n");
	}
	init_sword(2);
	setup();
}
