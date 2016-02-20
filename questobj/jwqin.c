//jiaowei qin 焦尾琴

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIM"焦尾琴"NOR,({"jiaowei qin","qin"}));
	set("taskobj", 1);
	set_weight(500);
	if(clonep())
		 set_default_object(__FILE__);
	else{
		set("unit","张");
		set("value",0);
		set("material","steel");
		set("long","相传这便是当年蔡文姬从火中所救出的焦木做成的美琴，琴的尾端仍可见焦黑色。\n");
		set("wield_msg",HIY"$N伸手轻轻一挥,一张焦尾琴便已出现在$N手中.\n"NOR);
		set("unwield_msg",HIY"$N十指一拂，琴声曳然而止。$N收起焦尾琴，放进背着的包袱里。\n"NOR);
		set("unequip_msg",HIY"你十指一拂，琴声曳然而止。你收起焦尾琴，放进背着的包袱里。.\n"NOR);
	}
	setup();
}

int wield()
{
	object ob = environment();

/*	if (ob && !wizardp(ob)) {
		tell_object(ob, name() + "是巫师用品，你不能使用，请马上向巫师报告，否则后果自负。\n");
		call_out("let_him_die", 300, ob);
		return 0;
	}*/
	return ::wield();
}
/*
void let_him_die(object ob)
{
	if (ob = environment()) {
		ob->add("combat_exp", -30000);
		ob->set_temp("last_damage_from", "盗用巫师用品中毒");
		ob->die();
	}
}
*/
