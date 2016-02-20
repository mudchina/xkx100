// maque.c

inherit NPC;

void create()
{
	set_name("麻雀", ({ "ma que"}));
	set("race", "飞禽");
	set("age", 3);
	set("long", "一只小麻雀，在石室里飞上飞下。\n");
	set("attitude", "peaceful");

	set("combat_exp", 300);
	set_temp("apply/attack", 3);
	set_temp("apply/defense", 5);
	set_temp("apply/armor", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		"麻雀唧唧喳喳叫了几声。\n",
		"麻雀扑腾着翅膀。\n",
		"麻雀一下撞到墙上，“碰”地一声又掉在地上。\n",
	}) );

	setup();
}
