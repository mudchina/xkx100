// /d/shenlong/npc/snake.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("¶¾Éß", ({ "snake", "she" }) );
	set("race", "ÅÀÉß");
	set("age", 4 + random(10));
	set("long", "Ò»Ö»ÓÐ×ÅÈý½ÇÐÎÄÔ´üµÄÉß£¬Î²°ÍÉ³É³×öÏì¡£\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("cor", 30);

	set("qi", 300);

	set("combat_exp", 5000 + random(5000));

	set_temp("apply/attack", 15+random(10));
	set_temp("apply/damage", 6+random(10));
	set_temp("apply/armor", 2+random(10));

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 20 + random(40) +
		victim->query_condition("snake_poison"));
}

#include "snake.h"

