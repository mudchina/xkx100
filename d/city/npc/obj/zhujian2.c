// zhujian2.c 竹剑
// 可以卖的竹剑，2两银子

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("竹剑", ({ "zhu jian", "jian", "sword"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 2000);
		set("material", "bamboo");
		set("long", 
"这是一把做工精致的竹剑，剑柄用细帆布包裹，剑身稍窄，剑尖处用布包了起来以免误伤同伴。\n");
		set("wield_msg", "$N拿出一把练剑用的$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_sword(1);
	setup();
}
 
