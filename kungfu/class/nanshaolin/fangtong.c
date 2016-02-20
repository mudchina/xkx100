// Npc: /kungfu/class/nanshaolin/fangtong.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("方通", ({ "fang tong", "fang", "tong"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "知客僧");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 30);
	set_skill("zhanzhuang-gong", 30);
	set_skill("dodge", 30);
	set_skill("yiwei-dujiang", 30);
	set_skill("cuff", 30);
	set_skill("shaolin-cuff", 30);
	set_skill("leg", 30);
	set_skill("shaolin-leg", 30);
	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "shaolin-cuff");
	map_skill("leg", "shaolin-leg");
	map_skill("parry", "shaolin-cuff");
	prepare_skill("cuff", "shaolin-cuff");
	prepare_skill("leg", "shaolin-leg");

	create_family("南少林派", 21, "弟子");

	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

int accept_object(object who, object ob,object me)
{
	mapping fam; 
	me=this_object();
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
	{
		command("hehe "+who->query("id"));
		command("say 你给我东西有什么企图？！");
		return 0;
	}
	if(!who->query_temp("lunzhi"))
	{
		command("say 你的令牌是那来的，轮值必须得到大苦大师的允许！");
		return 0;
	}
	if(ob->query("name")=="轮值令")
	{
		command( "say 好吧，你既然有大苦大师的令牌，你就在这和我在这里一起守卫吧。");
//		who->apply_condition("sl_lunzhi",random(5)+15);
		who->apply_condition("sl_lunzhi", 2);
		who->set_temp("lunzhied",1);
		return 1;
	}
	return 1;
}
#include "/kungfu/class/nanshaolin/fang.h";

