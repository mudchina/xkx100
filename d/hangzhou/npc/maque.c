// maque.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
	set_name("麻雀", ({ "maque"}));
	set("race", "飞禽");
	set("age", 3);
	set("long", "一只小麻雀，在树枝间跳上跳下。\n");
	set("attitude", "peaceful");

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		"麻雀在你头上打个转，又飞回树上。\n",
		"麻雀唧唧喳喳叫了几声。\n",
	}) );

	setup();
}
