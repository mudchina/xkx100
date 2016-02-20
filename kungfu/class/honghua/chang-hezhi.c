// Last Modified by winder on Sep. 12 2001
// chang-hezhi.c 常赫志

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("常赫志", ({ "chang hezhi", "chang", "hezhi" }));
	set("title", HIR"红花会"HIG"五当家"NOR);
	set("nickname", HIB"黑无常"NOR);
	set("long", 
"他身材又高又瘦，脸色蜡黄，眼睛凹进，眼角上有一粒黑痣，眉毛
斜斜的倒垂下来，形相甚是可怖。他是青城派慧侣道人的徒弟。黑砂
掌的功夫，江湖上无人能敌。黑白无常两兄弟是川江上著名的侠盗，
一向劫富济贫，不过心狠手辣，因此得了这难听的外号。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 14);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 500000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("strike", 120);
	set_skill("honghua-shengong", 120);
	set_skill("youlong-shenfa", 180);
	set_skill("heisha-zhang", 180);

	map_skill("dodge", "youlong-shenfa");
	map_skill("force", "honghua-shengong");
	map_skill("parry", "heisha-zhang");
	map_skill("strike", "heisha-zhang");
	prepare_skill("strike", "heisha-zhang");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({				
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set("double_attack", 1);
	create_family("红花会", 2, "弟子");

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	ob = this_player();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chang hezhi")
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

