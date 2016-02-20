// 冰魄银针。/kungfu/class/gumu/obj/yinzhen.c
// Spacenet@FXLT 1.1.2000

#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void init()
{
	add_action("do_bawan", "bawan");
}

void create()
{
	set_name(HIC"冰魄银针"NOR, ({ "ice_sting", "zhen" })); 
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
	set_amount(1);
	init_throwing(25);
	setup();
}

int do_bawan()
{
	if ((int)this_player()->query_condition("ice_sting") < 10) {
		tell_object(this_player(), "你看着手中的银针觉得有趣，把针身的花纹细细摸了一遍。\n");
		tell_object(this_player(), HIB "你突然觉得手掌麻麻的有些不太灵便，猛然惊觉：“针上有毒，如此把玩，岂不危险？”忙张开手掌\n抛下银针，只见两手掌心已深黑如墨，手臂麻木感渐渐上升，心中大骇，忍不住便要哭出声来。\n" NOR);
		this_player()->apply_condition("ice_sting", 30);
	}	
	destruct(this_object());
	return 1;
}
