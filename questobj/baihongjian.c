// baihongjian.c 白虹剑

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"白"HIM"虹"HIG"剑"NOR,({ "baihongjian", "sword", "jian" }));
	set_weight(8000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一口削铁如泥的宝剑。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄寒光闪闪的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	setup();
}
