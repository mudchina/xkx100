// Last Modified by winder on Apr. 25 2001
// wandao.c
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("蒙古弯刀", ({ "wan dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄亮晃晃的钢刀，是蒙古官兵的常备武器。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(30);
	setup();
}

