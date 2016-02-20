// luoyz_club.c
#include <weapon.h>
#include <ansi.h>
inherit CLUB;

void create()
{
	set_name(RED"金箍棒"NOR, ({ "jingubang", "club" }));
	set_weight(6000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N往腰中一摸，拿出了一把$n，端在手中。\n");
		set("unwield_msg", "$N手中$n抖出一个棍花，眨眼间已然不见影踪。\n");
	}
	setup();
}

