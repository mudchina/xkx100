// Last Modified by winder on Sep. 12 2001
// wuchen.c 无尘道长

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("无尘道长", ({ "wuchen daozhang", "wuchen" }));
	set("title", HIR"红花会"HIG"二当家"NOR);
	set("nickname", HIB"追魂夺命剑"NOR);
	set("long", "他是红花会坐第二把交椅的无尘道长，\n红花会中数他剑法最好，\n他年纪好像在四十岁左右，身形瘦削，颌下胡须无风自动，脸上表情不怒自威。\n");
	set("gender", "男性");
	set("class", "taoist");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("int", 23);
	set("con", 26);
	set("dex", 27);
	set("max_qi", 2200);
	set("max_jing", 2000);
	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 100);
	set("combat_exp", 3500000);
	set("score", 160000);
	set_skill("force", 180);
	set_skill("honghua-shengong",180);
	set_skill("dodge", 180);
	set_skill("youlong-shenfa", 180);
	set_skill("hand", 180);
	set_skill("benlei-shou", 180);
	set_skill("parry", 180);
	set_skill("sword", 190);
	set_skill("zhuihun-jian", 190);
	set_skill("literate", 50);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("parry", "zhuihun-jian");
	map_skill("sword", "zhuihun-jian");
	map_skill("hand", "benlei-shou");
	prepare_skill("hand", "benlei-shou");

        set("env/wimpy", 60);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhuihun" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

	create_family("红花会", 2, "弟子");
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="wuchen daozhang")
	{
		command( "chat "+ob->query("name")+"！你这等邪恶奸诈之徒，我红花会岂能容你！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","红花会" + RED + "弃徒" NOR);
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 10000)
	{
		command("say 哼！");
		command("say 这位" + RANK_D->query_respect(ob) + "为人之道似乎不怎么样！");
		return;
	}
	command("say 不错，不错，我就收下你了！");
	command("recruit " + ob->query("id"));
}

