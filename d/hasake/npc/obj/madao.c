// madao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("马刀", ({ "ma dao", "blade", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄磨得雪亮的马刀，是哈萨克男子的标志。\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(25);
	setup();
}
