// mi.c 米为义
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("米为义", ({ "mi weiyi", "mi", "weiyi" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 25);
	set("attitude", "peaceful");
	set("per", 20);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 30);
	set("max_qi",1500);
	set("max_jing",800);
	set("combat_exp", 1000000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("hengshan-sword", 150);
	set_skill("qiuyan-nanhui", 150);
	set_skill("luoyan-hand", 150);
	set_skill("huiyan-xinfa",100);	
	set_skill("literate", 100);	

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	prepare_skill("hand", "luoyan-hand");

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.yunwu" :),
		(: perform_action, "hand.jinghan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	create_family("衡山派", 14, "弟子");
	setup();

	carry_object(WEAPON_DIR+"sword/xijian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 入我门来，定须光大我衡山一派。");
	command("recruit " + ob->query("id"));
}
