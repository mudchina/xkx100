// yanjing.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("眼镜蛇", ({ "yanjing she", "yanjing", "snake", "she" }) );
	set("race", "爬蛇");
	set("age", 10);
	set("long", "一条眼镜蛇，对着你立了起来。\n");
	set("attitude", "peaceful");
	set("combat_exp", 4500);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 10);
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
	victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 10);
	return 0;
}
