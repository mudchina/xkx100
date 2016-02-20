// youlong.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC"游龙剑"NOR, ({ "youlong sword", "youlong", "sword" }) );
	set_weight(8000);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是把看起来很普通的长剑，但仔细一看，剑身上有几条细纹闪烁不定。\n");
		set("value", 0);
		set("material", "blacksteel");
		set("wield_msg", "只听见「飕」地一声，$N的手中已经多了一把寒光四射的宝剑——$n。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	setup();
}


