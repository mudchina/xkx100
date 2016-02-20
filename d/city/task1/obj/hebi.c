// hebi.c 鹤嘴笔

#include <weapon.h>
inherit DAGGER;

void create()
{
	set_name("鹤嘴笔", ({ "hebi" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("long", "这是一支笔端锐如鹤嘴，却是晶光闪亮的兵器。\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "steel");
		set("wield_msg", "$N抽出一支$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_dagger(40);
	setup();
}
