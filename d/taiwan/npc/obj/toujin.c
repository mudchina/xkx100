// toujin.c
// Last Modifyed by Ahda on Jan. 4 2002
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("头巾", ({ "tou jin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "条");
		set("long", "这是一条头巾，用以缠绕头部。\n");
		set("value", 1500);
		set("armor_prop/dodge", -5);
	}
	setup();
}
