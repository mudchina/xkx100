// Last Modified by Sir on May. 22 2001
// jing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <command.h>
#include "hengshan.h";
string ask_for_join();
string ask_yao();
void create()
{
	set_name("定静师太", ({ "dingjing shitai", "shitai", "dingjing" }) );
	set("long", "她是恒山派的定静师太，身穿道袍，眉目之间有一股祥和之气。\n"
			"自然而然的有股威严。\n");
	set("gender", "女性");
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"join"  : (: ask_for_join :),
		"天香断续膏" : (: ask_yao :),
		"还俗"  : "恒山弟子，不能还俗。",
		
	]));
	set("env/wimpy", 60);	

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield chacngjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
	}));


	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 1500000);
	set("score", 1000);
	set("yao_count", 1);
	
	set_skill("unarmed", 180);
	set_skill("sword", 200);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 150);
	set_skill("baiyun-xinfa",180);	
	set_skill("hengshan-jian", 300);
	set_skill("chuanyun-shou",300);
	set_skill("tianchang-zhang",300); 
	set_skill("lingxu-bu", 250);
	set_skill("literate", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	create_family("恒山派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫尼不收俗家弟子。");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say 你若能多为侠义之举，当能承我衣钵。\n");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能努力行善，济度众生，以光大我恒山派。");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "仪" + name[2..3];
	command("say 从今以后你的法名叫做" + new_name + "。");	
	ob->set("name", new_name);
}

string ask_yao()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="dingjing shitai")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此话从何谈起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你来晚了，天香断续膏刚巧给人了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/tianxianggao");
	ob->move(this_player());
	return "好吧，这块天香断续膏就先给你吧。";
}
