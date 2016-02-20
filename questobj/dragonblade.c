// dragonblade.c 屠龙刀

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(BLU"屠龙刀"NOR, ({ "dragon_blade", "blade", "dao" }));
	set_weight(10000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "此刀由郭靖黄蓉夫妇打造，是天下神兵。\n");
		set("material", "steel");
		set("value",0);
		set("wield_msg", HIB "猛见黑光一闪，屠龙刀跃入$N掌中。瞬时天地间弥漫着\n一片黑暗的杀意中。\n" NOR);
		set("unwield_msg", HIB "$N掌中刀气渐敛，天地间的肃杀之气慢慢散去。\n" NOR);
	}
	setup();
}

