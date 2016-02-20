// luzhang.c 鹿角杖

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("鹿角杖", ({ "luzhang" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根短杖，杖头分叉，作鹿角之形，通体黝黑，不知是何物铸成。\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(50);
	setup();
}
