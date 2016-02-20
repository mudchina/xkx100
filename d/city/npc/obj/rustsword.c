// rustsword.c

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(RED"长剑"NOR, ({ "rustsword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄锈迹斑斑的钢剑，不过似乎隐藏着一些光芒。\n");
		set("value", 400000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(10);
	setup();
}
