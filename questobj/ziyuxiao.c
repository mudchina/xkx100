// Last Modified by winder on Nov. 17 2000
// ziyuxiao.c 紫玉箫
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(MAG"紫玉箫"NOR,({"ziyu xiao","xiao"}));
	set_weight(1000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","支");
		set("value",0);
		set("material","gem");
		set("unique", 3);
		set("wield_neili", 50);
		set("wield_maxneili", 500);
		set("long","这是一支晶莹剔透的用罕见的"MAG"紫玉"NOR"做的箫，看起来十分珍贵。\n");
		set("wield_msg","$N伸手轻轻一招，一支$n已出现在$N手中。\n");
		set("unwield_msg","$N一声清啸，将$n插回腰间。\n");
	}
	setup();
}
