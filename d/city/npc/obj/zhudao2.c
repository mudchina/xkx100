// zhudao2.c 竹剑
// 可以卖的竹刀，2两银子

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("竹刀", ({ "zhu dao", "dao", "blade"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 2000);
		set("material", "bamboo");
		set("long", 
"这是一把做工精致的竹刀，刀柄用细帆布包裹，刀身稍弯，刀刃处特意加厚，以免误伤同伴。\n");
		set("wield_msg", "$N抽出一把练刀用的$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_blade(1);
	setup();
}
 
