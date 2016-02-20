// Room: /d/xingxiu/obj/baihuqiu.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"°×ºüôÃ"NOR, ({"baihu qiu", "huqiu", "qiu", "cloth"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¼þ");
		set("value", 1000);
		set("material", "fur");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

