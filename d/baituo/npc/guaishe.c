// guaishe.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("怪蛇", ({ "guai she", "snake", "she" }) );
	set("race", "爬蛇");
	set("age", 30);
	set("long", "一条三尺来长的眼镜王蛇。\n");
	set("attitude", "aggressive");
	set("combat_exp", 5500);
	set_temp("apply/attack", 250);
	set_temp("apply/defense", 250);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
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
	victim->apply_condition("bt_poison", victim->query_condition("bt_poison") + 20);
	return 0;
}
