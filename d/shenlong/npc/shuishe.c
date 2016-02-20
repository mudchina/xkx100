// /d/shenlong/npc/shuishe.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("水蛇", ({ "snake", "shuishe", "she" }) );
	set("race", "爬蛇");
	set("age", 4);
	set("long", "一条小溪里的小蛇。\n");
	set("attitude", "peaceful");

	set("qi",100);

	set("str", 25);
	set("cor", 28);

	set("combat_exp", 5000 + random(2000));
	set_temp("apply/attack", 10 + random(10));
	set_temp("apply/damage", 5 + random(5));
	set_temp("apply/armor", 2 + random(10));

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 20 +
		victim->query_condition("snake_poison"));
}

#include "snake.h"
