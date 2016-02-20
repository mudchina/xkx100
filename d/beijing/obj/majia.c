// majia.c

#include <armor.h>
#include <ansi.h>

inherit WAIST;

void create()
{
	set_name(HIM "小马甲" NOR, ({ "waist coat","waist","coat" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n这是凌儿的胸甲。粉红色的小马甲上绣着几只鸳鸯，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 50000);
		set("material", "丝");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

