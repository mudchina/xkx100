// zhenzhu.c 珍珠 
#include <armor.h>
 
inherit CLOTH;
 
void create()
{
	set_name("大珍珠", ({ "zhenzhu" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "个");
		set("long", "这是一个大珍珠，很值钱。\n");
		set("value", 30000);
		set("armor_prop/dodge", 5);
	}
	setup();
}
