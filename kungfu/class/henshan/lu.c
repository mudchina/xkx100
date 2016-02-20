// lu.c 鲁连荣
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("鲁连荣", ({ "lu lianrong", "lu", "lianrong" }) );
	set("nickname", HIY"金眼雕"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 13);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("max_qi",1800);
	set("max_jing",1200);
	set("combat_exp", 1800000);
	set("shen_type", 1);

	set_skill("unarmed", 160);
	set_skill("hand", 160);
	set_skill("sword", 180);
	set_skill("force", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("hengshan-sword", 250);
	set_skill("qiuyan-nanhui", 250);
	set_skill("luoyan-hand", 250); 
	set_skill("huiyan-xinfa",160);       

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
	carry_object("/clone/cloth/cloth")->wear();
}

