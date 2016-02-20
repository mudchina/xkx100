// xu.c 静虚师太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
int peiyao();
int liandan();
void create()
{
	set_name("静虚师太", ({ "jingxu shitai","jingxu","shitai"}));
	set("long", "她是峨嵋派二师姐，峨嵋门下多年，一套峨嵋掌法名动江湖。据说
对配药和炼制霹雳弹颇有造诣。\n");
	set("gender", "女性");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 10000);
	set("class", "bonze");
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"配药"  : ( : peiyao :),
		"霹雳弹": ( : liandan : ),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 20);

	set("max_qi", 1000);
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
	set_skill("finger", 100);
	set_skill("parry", 90);
	set_skill("strike", 80);
	set_skill("blade", 100);
	set_skill("literate", 90);
	set_skill("mahayana", 100);
	set_skill("jinding-zhang", 120);
	set_skill("tiangang-zhi", 150);
	set_skill("yanxing-dao", 150);
	set_skill("zhutian-bu", 150);
	set_skill("linji-zhuang", 100);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
//		(: perform_action, "sword.mie" :),
		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),		
		(: exert_function, "powerup" :),				
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object(WEAPON_DIR"gangdao")->wield();
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
		command ("say 阿弥陀佛！贫尼不收弟子。\n");
		command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
		return;
	}

	if( (string)ob->query("gender") != "女性" )
	{
		command ("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
		return;
	}
	if ((int)ob->query("shen") < 100)
	{
		command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
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

int peiyao()
{
	object me = this_player();
	object ob = this_object();
	object obj;
	int i;

	if(!objectp(present("caoyao 3",me)))
	{
		command("say 你的身上没有那么多草药。");
		return 1;
	}
	for(i=0;i<3;i++)
	{
		obj=present("caoyao",me);
		destruct(obj);
	}
	command("smile");
	command("say 好吧，我就给你配药了。");
	obj=new("/d/emei/obj/zhongyao");
	obj->move(me);
	message_vision("静慈师太给$N一包中药。\n",me);
	return 1;
}
int liandan()
{
	object me = this_player();
	object ob = this_object();
	object obj;
	int i;
	if(!objectp(present("liuhuang",me)))
	{
		command("say 你的身上没有炼制霹雳弹用的硫磺。");
		return 1;
	}
	obj=present("liuhuang",me);
	destruct(obj);
	command("smile");
	command("say 好吧，我就给你炼制一粒霹雳弹。");
	obj=new("/d/emei/obj/pilidan");
	obj->move(me);
	message_vision("静慈师太给$N一粒霹雳弹。\n",me);
	return 1;
}
#include "emei.h"
