// alabo.c
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("阿拉伯商人", ({ "alabo shangren", "shangren", "trader" }));
	set("gender", "男性");
	set("age", 35);
	set("long","一个阿拉伯商人。头上包着一块白巾。\n");
	set("attitude", "friendly");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 40);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"阿拉伯商人对你挤了一下眼睛。\n",
		"阿拉伯商人对你说：阿萨兰马离贡，穆罕默德瑞素阿拉。你没听懂。\n",
		(: random_move :)
	}) );
	carry_object("/clone/weapon/blade/wandao")->wield();
	carry_object("/clone/cloth/changpao")->wear();
	add_money("silver", 20);
}


