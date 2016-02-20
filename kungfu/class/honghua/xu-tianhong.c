// Last Modified by winder on Sep. 12 2001
// xutianhong.c 徐天宏

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("徐天宏", ({ "xu tianhong", "xu", "tianhong" }));
	set("nickname", HIM"武诸葛"NOR);
	set("title", HIR"红花会"HIG"七当家"NOR);
	set("long","他是红花会的七当家，\n他年纪好像在四十上下，身材矮小，足智多谋，是红花会的智囊军师。武功也颇不弱，冷静持重。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 40);
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
	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("force", 120);
	set_skill("honghua-shengong", 120);
	set_skill("dodge", 120);
	set_skill("youlong-shenfa", 180);
	set_skill("hand", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("zhuihun-jian", 180);
	set_skill("benlei-shou", 180);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	create_family("红花会", 2, "弟子");
	
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < 1000 &&
		ob->query("family/master_id")=="xu tianhong")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我岂能仍是你的师父。\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 2000)
	{
		command("say 我红花会收徒极严。");
		command("say 这位" + RANK_D->query_respect(ob) + "平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
}


