// 血滴子

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(HIR"血滴子"NOR, ({ "xuedi zi", "xuedi" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "乌黑的一柄兵器，似乎沾染了许多江湖英雄的鲜血，暗暗
透出一股血腥的味。\n");
		set("value", 0);
		set("material", "leather");
		set("wield_msg", "$N暗暗冷笑，抽身反手，撒出一件乌黑兵器。\n");
		set("unwield_msg", "$N暗自一声冷哼，不屑地收回血滴子。\n");
	}
	setup();
}

