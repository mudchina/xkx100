// eagleg.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
        set_name("秃鹰", ({ "eagle" }) );
	set("race", "飞禽");
        set("age", 3);
        set("long", "一只黑色的秃鹰，秃头黑羽，好吃腐尸，看起来讨厌极了。\n");
        set("attitude", "peaceful");

        set("combat_exp", 3000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 10);

        setup();
}
