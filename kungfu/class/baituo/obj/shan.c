// gangjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("纸扇", ({ "zhi shan", "shan" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把制作精美的纸扇，上面写着“白驼少主”四个镂金纂字。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N从兜里掏出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n放会兜里。\n");
	}
	init_dagger(100,0);
	setup();
}
