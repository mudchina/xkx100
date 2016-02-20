// yufu.c 渔夫
// Last Modified by winder on Jul. 12 2002

inherit NPC;

void create()
{
	set_name("渔夫", ({ "yu fu","fu" }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "岛上以打鱼为生的渔夫。\n");
	set("combat_exp", 8800);
	set("shen_type", 0);
	set("attitude", "friendly");

	set("apply/attack",  30);
	set("apply/defense", 30);

	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	add_money("coin", 50);
}
