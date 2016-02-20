// wen-tailai.c 文泰来
// Last Modified by winder on Sep. 12 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("文泰来", ({ "wen tailai", "wen", "tailai" }));
	set("title", HIR"红花会"HIG"四当家"NOR);
	set("nickname", HIM"奔雷手"NOR);
	set("long","他是红花会的四当家，身穿一件青色长衫。\n他年纪好像在三十上下，身材十分槐梧，双手青筋突出，布满了老茧。十五岁起浪荡江湖，手掌下不知击毙过多少神奸巨憝、凶徒恶霸。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 32);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2000);
	set("max_jing", 1500);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
	set("combat_exp",800000);
	set("score", 100000);

	set_skill("force", 100);
	set_skill("honghua-shengong", 100);
	set_skill("dodge", 100);
	set_skill("youlong-shenfa", 150);
	set_skill("hand", 100);
	set_skill("benlei-shou", 250);
	set_skill("parry", 100);
	set_skill("blade", 100);
	set_skill("qiuge-dao", 150);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "qiuge-dao");
	map_skill("blade", "qiuge-dao");
	prepare_skill("hand", "benlei-shou");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("红花会", 2, "弟子");
	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="wen tailai")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我岂能仍是你的师父。\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000)
	{
		command("say 我红花会收徒极严。");
		command("say 这位" + RANK_D->query_respect(ob) + "平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
}

