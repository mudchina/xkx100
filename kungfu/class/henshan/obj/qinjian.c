// qinjian.c
// Last Modified by winder on Sep. 2 2001

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("琴剑", ({ "qin jian", "jian", "sword" }) );
	set_weight(1400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 700);
		set("material", "steel");
		set("long", "这是一把又细又长的剑，反手插在胡琴里。是衡山派掌门莫大先生的配剑。\n");
		set("wield_msg", "只听“叮当”一声轻响，$N从琴底抽出一把极细极亮的剑来。\n");
		set("unequip_msg", "“叮当”一声响，$N反手把剑插回胡琴底。\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(50);
	setup();
}
