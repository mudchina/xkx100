// xuan.c 静玄师太
//Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{

	set_name("静玄师太", ({ "jingxuan shitai","jingxuan","shitai"}));
	set("long","她是峨嵋派大师姐，跟随灭绝师太二十余载，峨嵋派的基本功夫已尽得所传。\n");
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 10000);
	set("class", "bonze");
	set("inquiry",([
		"剃度" : (: ask_for_join :),
		"出家" : (: ask_for_join :),
		"还俗" : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 250000);
	set("score", 1000);
	set_skill("persuading", 80);
	set_skill("throwing", 80);
	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("finger", 95);
	set_skill("parry", 100);
	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 150);
	set_skill("tiangang-zhi", 120);
	set_skill("huifeng-jian", 150);
	set_skill("zhutian-bu", 120);
	set_skill("linji-zhuang", 100);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}
void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")!="bonze" )
	{
		command("say 阿弥陀佛！贫尼不收弟子。\n");
		command("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
		return;
	}
	if( (string)ob->query("gender") != "女性" )
	{
		command("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
		return;
	}
	if ((int)ob->query("shen") < 100)
	{
		command("say "+RANK_D->query_respect(ob)+"你行侠仗义之事还做的不够。");
		return;
	}
	if ((int)ob->query_skill("mahayana",1) <50)
	{
		command("say 你大乘佛法的修为还要提高些。");
		return;
	}
	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}
#include "emei.h"
