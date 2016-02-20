// Obj: /d/lingxiao/obj/ban.c
// Last Modified by winder on Jul. 15 2001
//LUCAS 2000-6-18
#include <ansi.h>
#include <armor.h>
inherit HEAD;

string *names = ({
	HIW"梅瓣"NOR,
	HIG"梅瓣"NOR,
	CYN"梅瓣"NOR,
	HIC"梅瓣"NOR,
	HIY"梅瓣"NOR,
	HIR"梅瓣"NOR,
});
void create()
{
	int i = random(sizeof(names));
	set_name(names[i], ({"mei ban","nam"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "一片刚刚从树上飘落的梅瓣。\n");
		set("value", 0);
		set("material", "plant");
		set_weight(4000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unequip_msg", "$N轻轻地把$n从头上摘了下来。\n");
	}
	setup();
}

