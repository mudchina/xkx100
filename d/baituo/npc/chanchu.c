// chanchu.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIW"玄冰蟾蜍"NOR, ({ "xuanbing chanchu", "chanchu", "hama", "xuanbing" }) );
	set("race", "野兽");
	set("age", 40);
	set("long", "一只通体雪白的蟾蜍，趴在青石板上一动不动。\n");
	set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "后肢", "肚皮" }) );
	set("verbs", ({ "hoof"}) );
	set("combat_exp", 15000);
	set("max_jing", 500);
	set("max_qi", 500);
	set("jing", 500);
	set("qi", 500);
	set_temp("apply/attack", 90);
	set_temp("apply/defense", 90);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 100);
	setup();
}

void init()
{
	object ob = this_player();
	::init();
	if (interactive(ob) && !ob->query_skill("hamagong", 1))
	{
		this_object()->kill_ob(this_player());
	}
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("cold_poison", victim->query_condition("cold_poison") + 10);
	return 0;
}
