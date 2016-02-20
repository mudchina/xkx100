// Room: /d/kunlun/npc/obj/necklace.c 金项链
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(HIY"金项链"NOR, ({ "golden necklace", "necklace", "lace" }));
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("value", 2500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
