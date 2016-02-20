// 银匕首.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(WHT"银匕首"NOR, ({ "yin bishou", "jian", "bishou" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄闪着亮丽银光的匕首，十分锋利。\n");
		set("value", 5000);
		set("material", "silver");
		set("wield_msg", "$N手指轻摆，弹出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放回衣袖。\n");
	}
	init_sword(35);
	setup();
}
