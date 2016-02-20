// fox.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
void create()
{
	set_name("狐狸", ({ "fox", "huli", "hu" }) );
	set("race", "走兽");
	set("age", 4);
	set("long", "一只多疑成性的狐狸。\n");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 10000);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 10);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"狐狸向后挪了挪，很是戒备的神情。\n",
		"狐狸瞪着多疑的眼光冲你看，全身一副很紧张的模样。\n",
	}) );
}

