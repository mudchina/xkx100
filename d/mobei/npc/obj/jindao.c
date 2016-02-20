// Last Modified by winder on May. 25 2001
// jindao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(YEL"金刀"NOR, ({"jindao", "blade", "dao"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","把");
		set("long","刀鞘是黄金所铸,刀柄尽头处铸了一个黄金的虎头,狰狞生威。\n");
		set("value", 5000);
		set("material","gold");
		set("wield_msg", "$N将$n抽出鞘来，只觉寒气逼人，刃锋上隐隐有血光之印。\n");
		set("unwield_msg", "$N将手中的$n插回黄金刀鞘。\n");
	}
	init_blade(60);
	setup();
}
