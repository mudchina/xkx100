// yanjing1.c
// Last Modified by winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("眼镜王蛇", ({"yanjing wangshe", "snake", "she", "wangshe" }));
	set("race", "爬蛇");
	set("age", 10);
	set("long", "一条三尺来长的眼镜王蛇。\n");
	set("attitude", "peaceful");
	set("combat_exp", 5500);
	set_temp("apply/attack", 55);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	setup();
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison", victim->query_condition("snake_poison") + 15);
	return 0;
}
