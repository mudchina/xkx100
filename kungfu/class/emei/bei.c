// bei.c 贝锦仪

inherit NPC;
inherit F_MASTER;
int ask_for_ji();
void create()
{
	set_name("贝锦仪", ({ "bei jinyi","bei","jinyi"}));
	set("long", "她是峨嵋派的第四代俗家弟子。\n");
	set("gender", "女性");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("no_get", 1);
	set("env/wimpy", 60);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("inquiry",([
		"倚天剑" : "师父把她交给纪师姊了。",
		"纪晓芙" : (: ask_for_ji :),
	]));

	set("combat_exp", 150000);
	set("score", 1000);
	set("ji_count", 1);
	set_skill("throwing", 30);
	set_skill("persuading", 50);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("finger", 85);
	set_skill("parry", 70);
	set_skill("strike", 60);
	set_skill("sword", 60);
	set_skill("jinding-zhang", 90);
	set_skill("tiangang-zhi", 120);
	set_skill("huifeng-jian", 90);
	set_skill("zhutian-bu", 120);
	set_skill("linji-zhuang", 80);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),		
		(: perform_action, "finger.lingkong" :),			
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("combat_exp") > 10000) {
		command("say 我峨嵋注重清修，对弟子要求能忍受寂寞。");
		command("say 在江湖阅历方面，" + RANK_D->query_respect(ob) +
			"经历丰富，是否能在峨嵋修道？");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
}
int ask_for_ji()
{
	object ob = this_player();

	if(query("ji_count") > 0)
	{
		tell_object(ob,"贝锦仪说道：你找晓芙？看看有没有在舍身崖。\n"); 
		add("ji_count", -1);
		ob->set("marks/ji",1);
	}
	else tell_object(ob,"贝锦仪说道：你找晓芙？我也在找她呢。\n"); 
	return 1;
}
