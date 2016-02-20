// snow_sword.c 

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIB"风回"HIW"雪舞"HIG"剑"NOR, ({"snowsword","xue jian","sword"}));
	set_weight(400);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 0);
		set("material", "steel");
		set("long", "这是一把用来练舞的剑，剑身细长，轻巧尤锋利。\n");
		set("wield_msg", "$N抽出一把剑身细长的剑，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	setup();
}

