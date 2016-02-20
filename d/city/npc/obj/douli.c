// douli.c 暗器

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(BLK "油篓肩舆" NOR, ({"dou li"}) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "此舆用竹蔑做成如围，再加黑油以防雨。此舆之取乎轻便，而不取华丽者也。\n");
		set("value", 600);
		set("unit", "顶");
		set("armor_prop/armor",2);
		set("armor_prop/personality", 5);
		set("wear_msg","$N戴上一顶$n。\n");
		set("unequip_msg", "$N摘下头上的$n，拿在手里。\n");
	}
	setup();
}
