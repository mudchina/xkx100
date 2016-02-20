// song.c 宋远桥
// Last Modified by winder on Aug. 18 2002

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("宋远桥", ({ "song yuanqiao", "song" }));
	set("nickname", "武当首侠");
	set("long","他就是张三丰的大弟子、武当七侠之首的宋远桥。\n身穿一件干干净净的灰色道袍。\n他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 350000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 80);
	set_skill("tiyunzong", 120);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 150);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("taiji-jian", 120);
	set_skill("wudang-jian", 120);
	set_skill("wudang-quan", 120);
	set_skill("literate", 50);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("武当派", 2, "弟子");

	set("inquiry", ([
		"秘籍" : (: ask_me :),
	]));

	set("book_count", 1);

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 60)
	{
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 35000)
	{
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) + 
		"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到太极十三式啦。\n");
	return "好吧，这本「太极十三式」你拿回去好好钻研。";
}
