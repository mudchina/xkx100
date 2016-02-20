// weapon: /d/xingxiu/npc/obj/yaochu.c

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
	set_name(BLK"药锄"NOR, ({ "yao chu", "chu" }) );
	set("taskobj", 1);
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把采药用的药锄，已经有些生锈了。\n");
		set("value", 0);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}
	setup();
}

