// yusword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIG "玉环剑" NOR, ({ "yuhuan jian", "yuhuan", "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把翠玉色的剑。\n");
		set("value", 200000);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg", "$N从剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	}
	init_sword(40);
	setup();
}
