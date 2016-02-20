// Obj: /d/lingxiao/obj/mei.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
#include <armor.h>
inherit HEAD;

string *names = ({
	HIW"梅花"NOR,
	HIG"梅花"NOR,
	CYN"梅花"NOR,
	HIC"梅花"NOR,
	HIY"梅花"NOR,
	HIR"梅花"NOR,
});
void create()
{
	int i = random(sizeof(names));
	set_name(names[i], ({"mei hua","hua"}));
			set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", HIW"一朵梅花。\n");
		set("value", 0);
		set("material", "plant");
		
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
	}
	setup();
}

