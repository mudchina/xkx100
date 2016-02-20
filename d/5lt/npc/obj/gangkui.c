// gangkui.c 钢盔
 
#include <armor.h>
 
inherit HEAD;
 
void create()
{
	set_name("钢盔", ({ "helmet", "gangkui" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "顶");
		set("long", "这是一顶崭新的钢盔，用以保护头部。\n");
		set("value", 10000);
		set("armor_prop/armor", 30);
	}
	setup();
}