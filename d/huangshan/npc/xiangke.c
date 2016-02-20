// xiangke.c

inherit NPC;
void create()
{
	set_name("香客", ({ "xiang ke", "ke" }) );
	set("gender", (random(2)? "女性":"男性") );
	set("age", random(40)+10);
	set("long", "一个上山游玩的香客。\n");
	set("combat_exp", 5+random(5000));
	set("chat_chance", 70);
	set("chat_msg", ({
		(: random_move :),
		"香客指着周围的景色叹道：真美呀．．\n",
		"香客道：不愧为一座名山．．，还美过五岳呀！\n",
		"香客对你说道：你也是来游山的？\n",
		"香客对你说道：你看这儿多美呀！\n",
		"香客对你说道：我真的被这儿陶醉了！\n",
	}) );

	set("attitude", "friendly");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

