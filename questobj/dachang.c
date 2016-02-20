// cloth.c
//
// This is the basic equip for players just login.

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIB"鸟羽大氅"NOR, ({ "da chang" }) );
	set_weight(3000);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "领");
		set("long", "一领用秃鹰长羽织就的大氅. \n");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
	setup();
}

