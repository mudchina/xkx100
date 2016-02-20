// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
	set_name(HIC"鱼肠剑"NOR, ({"yuchang jian","jian"}) );
	set_weight(10000);
	set("taskobj", 1);
	set("unit", "柄");
	set("long", "这就是传说中的鱼肠剑。剑身细长，看上去异常锋利。\n");
	set("value",0);
	set("material", "steel");
	set("wield_msg", HIB "嗤地一声，$n"HIB"已在$N手中，周遭顿时弥漫冷冷的杀气。\n" NOR);
	set("unwield_msg", HIG "$N一扬手，$n"HIG"已入鞘。无声无息，却暗藏杀机。\n" NOR);
	setup();
}

