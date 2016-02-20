// chuan.c 橄榄核船

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(HIC "橄榄核船" NOR, ({"ganlanhe chuan", "chuan"}) );
	set_weight(100);
	set("taskobj", 1);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", @LONG
橄榄核船雕刻精致，中舱客四人，二人在后，一摇撸，一钮滨，窗棂皆可开
阖，眉目如画，外用退光漆盒，如药制橄榄形，红丝结络，可以佩身。
LONG
		);
		set("unit", "个");
		set("value", 0);
		set("armor_prop/armor",1);
		set("wear_msg", "$N把一个$n系在腰间。\n");
		set("unequip_msg","$N从腰间解下一个$n，拿在手里把玩。\n");
	}
	setup();
}

