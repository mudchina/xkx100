// fengling.c 风陵师太
// Modified by Winder Jul.2000
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("风陵师太", ({ "fengling shitai","fengling","shitai"}));
	set("long","她一副仙风道骨，与世无争模样，是峨嵋派的第二代掌门人。\n"); 
	set("gender", "女性");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("env/wimpy", 60);
	set("inquiry",([
		"剃度" : "贫尼只知除妖杀魔，不剃度弟子。",
		"出家" : "贫尼只知除妖杀魔，不剃度弟子。",
	]));

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 2500000);
	set("score", 1000);
	set_skill("persuading", 150);
	set_skill("throwing", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("literate", 100);
	set_skill("mahayana", 200);
	set_skill("buddhism", 200);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 200);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
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
	create_family("峨嵋派", 2, "掌门人");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
	mapping my_fam = ob->query("family");
	string name, new_name;
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}
	switch (random(2))
	{
		case 1: break;
		default:
			if ((string)ob->query("class")!="bonze" )
			{
				command ("say 阿弥陀佛！贫尼不收俗家弟子。");
				return;
			}
			else
			{
				command ("say 阿弥陀佛！贫尼不收弟子。");
				return;
			}
	}
	if ((int)ob->query_skill("mahayana",1)<120||
		(int)ob->query_skill("linji-zhuang",1)<120)
	{
		command("say 你本门的功夫修为还太低。");
		return;
	}
	if ((int)ob->query("shen") < 500000)
	{
		command("say "+RANK_D->query_respect(ob)+"你行侠仗义之事还做的不够。");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "灭" + name[2..3];
		ob->set("name", new_name);
		command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第三代弟子!");
	}

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}

