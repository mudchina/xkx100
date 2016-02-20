// hama.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("蟾蜍", ({ "chan chu", "chu", "hama" }) );
	set("race", "野兽");
	set("age", 10);
	set("long", "一只肥大的蟾蜍，趴在地上一动不动。\n");
	set("attitude", "peaceful");	
	set("limbs", ({ "头部", "身体", "后肢", "肚皮" }) );
	set("verbs", ({ "hoof"}) );
	set("combat_exp", 1900);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 8);
	set_temp("apply/damage", 8);
	set_temp("apply/armor", 8);
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
	victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 3);
	return 0;
}
