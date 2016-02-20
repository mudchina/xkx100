// tieqiao.c

#include <weapon.h>
inherit CLUB;

void create()
{
	set_name("铁锹", ({ "shenlong qiao", "tie qiao", "qiao" }));
	set_weight(17000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把挖地的铁锹，用精钢打制，木柄上雕着一条仰头吐信的怪蛇。\n");
		set("value", 5000);
		set("material", "steel");
		set("no_put",1);
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回后腰。\n");
		set("dig_times", 5);
	}
	init_club(15);
	setup();
}

