// heiyi.c
// Last Modified by winder on May. 25 2001

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(BLK"黑衣"NOR, ({"black cloth", "cloth"}));
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", BLK"一件铁掌帮众常穿的黑衣。\n"NOR);
		set("material", "cloth");
		set("unit", "件");
		set("value", 40);
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
	}
	setup();
}

