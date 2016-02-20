// Spacenet@FXLT 1.1.2000

#include <weapon.h>
#include <ansi.h>
inherit THROWING;

void create()
{
	set_name(HIC"冰魄银针"NOR, ({ "ice_sting", "zhen" })); 
	set("taskobj", 1);
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这就是武林中人闻之色变的冰魄银针，针身缕刻花纹，打造得极是精细，令人忍不住想把玩(bawan)一番。\n");
		set("value", 0);
		set("base_unit", "根");
		set("base_weight", 30);
		set("base_value", 0);
		set("meterial", "iron");
		set("wield_msg", "$N小心翼翼地取出一根冰魄银针当武器。\n");
		set("unwield_msg", "$N把银针放回衣囊中。\n");
	}
	setup();
}
