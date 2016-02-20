// wulai.c 无赖

inherit NPC;

void create()
{
	set_name("无赖", ({ "wu lai", "wulai" }));
	set("gender", "男性");
	set("age", 19);
	set("long", "他是一个成天游手好闲的无赖，赌钱赌得两眼红肿、脸色灰暗。\n");
	set("combat_exp", 2000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",2);
}
