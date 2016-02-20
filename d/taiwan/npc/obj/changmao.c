// changmao.c 长矛
// Last Modifyed by Ahda on Jan. 4 2002

#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("长矛", ({ "changmao" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "这是一根用木头削尖的长矛。\n");
		set("value", 0);
		set("rigidity",50);
		set("material", "bamboo");
		set("wield_msg", "$N掣出一杆$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n反别身后。\n");
	}
	init_spear(25);
	setup();
}

