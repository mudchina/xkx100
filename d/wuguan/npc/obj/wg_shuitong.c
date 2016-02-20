#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("水桶", ({ "shuitong" }));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "这是一个用圆木圈成的水桶，普通百姓的日常务农用品。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N 挑起$n挡在肩上。\n");
		set("unwield_msg", "$N将肩上的$n放了下来。\n");
	}
	init_hammer(4);
	setup();
}
