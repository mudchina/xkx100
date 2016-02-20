// /d/shenlong/npc/mangshe.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
int snake_attspeed(object);

void create()
{
	set_name("蟒蛇", ({ "snake", "mangshe", "she", "mang"}) );
	set("race", "爬蛇");
	set("age", 100);
	set("long", "一条碗口粗细的三角头巨蟒，有两丈多长。\n");
	set("attitude", "peaceful");

	set("str", 32);
	set("cor", 36);
	set("max_jing", 500);
	set("max_qi", 2000);

	set("combat_exp", 20000 + random(10000));

	set_temp("apply/attack", 50 + random(20));
	set_temp("apply/damage", 20 + random(10));
	set_temp("apply/dodge", 20 + random(10));
	set_temp("apply/armor", 20 + random(10));

	setup();
}

#include "snake.h"
