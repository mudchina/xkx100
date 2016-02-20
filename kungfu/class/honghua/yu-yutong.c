// Last Modified by winder on Sep. 12 2001
// yu-yutong.c 余鱼同

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("余鱼同", ({ "yu yutong", "yu" }));
	set("nickname", YEL"金笛秀才"NOR);
	set("title", HIR"红花会"HIG"十四当家"NOR);
	set("long","他是红花会的十四当家，\n身穿一件极为合体的白色长衫，\n他年纪好像在二十上下，身穿白色长衫，长身玉立，眉清目秀，风流英俊的书生。\n他是江南望族子弟，中过秀才。\n父亲因和一家豪门争一块坟地，官司打得倾家荡产，又被豪门借故陷害，瘐死狱中。\n余鱼同一气出走，得遇机缘，拜马真为师，弃文习武，刺死士豪后，亡命江湖。\n他为人机警灵巧，多识各地乡谈，在会中任联络四方、刺探讯息之职。\n");
	set("gender", "男性");
	set("class", "swordman");
	set("age", 21);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 100000);

	set_skill("force", 80);
	set_skill("honghua-shengong", 80);
	set_skill("dodge", 80);
	set_skill("youlong-shenfa", 120);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("benlei-shou", 120);
	set_skill("zhuihun-jian", 120);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("hand", "benlei-shou");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	prepare_skill("hand", "benlei-shou");

	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({	
		(: perform_action, "sword.zhuihun" :),
		(: perform_action, "hand.yunkai" :),			
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	create_family("红花会", 2, "弟子");

	setup();
	carry_object("/kungfu/class/baituo/obj/baipao")->wear();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="yu yutong")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我岂能仍是你的师父！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0)
	{
		command("say 我红花会收徒极严。");
		command("say 这位" + RANK_D->query_respect(ob) + "平时还要多做一些行侠仗义之事！");
		return;
	}
	command("say 好，你这个年青人还不错，我收下你了！");
	command("recruit " + ob->query("id"));
}

