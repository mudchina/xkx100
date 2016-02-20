// liu.c 刘正风
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("刘正风", ({ "liu zhengfeng", "liu" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("long", "一个胖老者。恂恂有礼，便如一个财主乡绅，有些小小的
富贵之气，又有些土气，但有时突然显出勃勃英气，不失
高手风范。\n");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 19);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 50);
	set("max_qi",3000);
	set("max_jing",1500);
	set("combat_exp", 2000000);
	set("shen_type", 1);

	set_skill("unarmed", 180);
	set_skill("hand", 180);
	set_skill("sword", 200);
	set_skill("force", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("hengshan-sword", 300);
	set_skill("qiuyan-nanhui", 250);
	set_skill("luoyan-hand", 250); 
	set_skill("huiyan-xinfa",180);       
	set_skill("luteplaying", 150);
	set_skill("literate", 150);	

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

	create_family("衡山派", 13, "弟子");
	setup();

	carry_object(WEAPON_DIR+"sword/xijian")->wield();
	carry_object(__DIR__"obj/luo_cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("huiyan-xinfa",1) < 120 ) 
	{
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	command("say 入我门来，定须光大我衡山一派。");
	command("recruit " + ob->query("id"));
}
