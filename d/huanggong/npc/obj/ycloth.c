// ycloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"黄马褂"NOR, ({ "yellow magua", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是件黄马褂，是当今御赐，极尽荣耀，极显恩宠。\n");
		set("unit", "件");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 150);
		set("armor_prop/personality", 3);
	}
	setup();
}
