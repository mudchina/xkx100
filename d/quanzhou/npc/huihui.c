// huihui.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("回回", ({ "hui hui", "huihui", "hui" }));
	set("gender", "男性");
	set("age", 25);
	set("long","一个虔诚回回，正跪在地上向西方膜拜。\n");
	set("attitude", "friendly");
	set("combat_exp", 1000);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	carry_object("/clone/cloth/changpao")->wear();
	add_money("silver", 5);
}


