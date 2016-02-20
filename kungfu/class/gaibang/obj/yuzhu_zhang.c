// bamboo_stick.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("玉竹杖", ({"yuzhu zhang", "zhu", "stick"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根泛着淡淡青光的竹杖。\n");
		set("value", 10000);
		set("material", "bamboo");
		set("wield_msg", "$N抽出一根青光闪闪的竹杖抓在手中。\n");
		set("unwield_msg", "$N把手中的玉竹杖插回腰中。\n");
	}
	init_staff(30);
	setup();
}	
