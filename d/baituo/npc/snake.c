// snake.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("黑冠巨蟒", ({ "snake", "she" }) );
	set("race", "爬蛇");
	set("age", 20);
	set("long", "一只庞然大物，它眼中喷火，好象要一口把你吞下。\n");
	set("attitude", "aggressive");
	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 500);
	set("max_jing", 500);
	set("str", 86);
	set("cor", 80);
	set("combat_exp", 100000);
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence", 80);

	setup();
}

