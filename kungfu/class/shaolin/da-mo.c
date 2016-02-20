// Npc: /kungfu/class/shaolin/da-mo.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>

void create()
{
	set_name("达摩老祖", ({
		"da mo",
		"da",
		"mo",
	}));
	set("long",
		"他是一位卷发络腮须的天竺老僧，身穿一袭邋遢金丝绣红袈裟。\n"
		"但却满面红光，目蕴慈笑，眼现智珠，一派得道高僧气势。\n"
                "他就是少林派开山鼻祖、当今武林的隐世高僧达摩祖师。\n"
	);

	set("title", HIR"少林开山祖师"NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 80);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3500);
	set("max_jing", 1000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 2000000);
	set("score", 500000);

	set_skill("buddhism", 180);
	set_skill("literate", 130);

	set_skill("blade", 200);
	set_skill("claw", 200);
	set_skill("club", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("whip", 200);

	set_skill("banruo-zhang", 300);
	set_skill("cibei-dao", 300);
	set_skill("damo-jian", 300);
	set_skill("fengyun-shou", 300);
	set_skill("fumo-jian", 300);
	set_skill("hunyuan-yiqi", 200);
	set_skill("jingang-quan", 300);
	set_skill("longzhua-gong", 300);
	set_skill("luohan-quan", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("pudu-zhang", 300);
	set_skill("qianye-shou", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("riyue-bian", 300);
	set_skill("shaolin-shenfa", 300);
	set_skill("weituo-gun", 300);
	set_skill("wuchang-zhang", 300);
	set_skill("xiuluo-dao", 300);
	set_skill("yingzhua-gong", 300);
	set_skill("yijinjing", 250);
	set_skill("yizhi-chan", 300);
	set_skill("zui-gun", 300);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("force", "yijinjing");
	map_skill("hand", "fengyun-shou");
	map_skill("parry", "nianhua-zhi");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");
	map_skill("whip", "riyue-bian");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");
		
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("少林派", 34, "弟子");
	setup();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] != 36 )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

        if ((ob->query_int() < 40) || (ob->query("PKS") > 3 )) 
        {
                command("say 万事都讲一个缘字。");
                command("say " + RANK_D->query_respect(ob) + "与佛无缘，还是请回吧。");
		return;
	}

	if (ob->query_skill("dodge",1)>=150 &&
		ob->query_skill("force",1)>=150 &&
		ob->query_skill("parry",1)>=150 &&
		ob->query_skill("buddhism",1)>=150)
	{
		command("say 老衲又得一可塑之才，真是大畅老怀 !");
		name = ob->query("name");
		new_name = "渡" + name[2..3];
		ob->set("name", new_name);
	
		command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派渡字辈弟子 !");
		command("recruit " + ob->query("id"));
	}
	else
		command("say 你现在就来找我也太早了点吧 !");
	return;
}

