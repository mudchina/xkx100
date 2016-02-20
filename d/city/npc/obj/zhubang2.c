// zhubang2.c 竹棒
// 可以卖的竹棒，2两银子

#include <weapon.h>
inherit STICK;

void create()
{
	set_name("竹棒", ({ "zhubang" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根做工精致的竹棒，棒端用细帆布包裹，以免误伤同伴。\n");
		set("value", 2000);
		set("material", "bamboo");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_stick(1);
	setup();
}
 
