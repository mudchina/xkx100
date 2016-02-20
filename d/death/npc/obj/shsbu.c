// shsbu.c
#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
	set_name(HIR "態指伏棒仮" NOR, ({ "shengsi bu" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "云");
		set("armor_prop/armor", 5);
		set("armor_prop/defense", 3);
	}
	setup();
}
