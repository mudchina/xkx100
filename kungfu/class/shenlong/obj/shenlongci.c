// shenlongchi.c 神龙刺

#include <weapon.h>
inherit HOOK;

void create()
{
	set_name(HIY"神龙刺"NOR, ({ "shenlong ci", "ci" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long","这是一柄短小晶亮、前带弯钩的兵器，是神龙岛的独门兵器。\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回后腰。\n");
	}
	init_hook(30);
	setup();
}

