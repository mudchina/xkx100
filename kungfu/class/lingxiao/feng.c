// Npc: /d/lingxiao/npc/feng.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("封万里",({"feng wanli","feng"}));
	set("nickname", HIR"风火神龙"NOR);
	set("gender", "男性");
	set("age", 20);
	set("long", 
		"他是凌霄城第六代弟子封万里，是第六代弟子中出类拔萃\n"
		"的人物，其剑法刚猛迅捷，如狂风，如烈火，得了个风火\n"
		"神龙的外号。但不知为何，他少了一只手臂，眼中全是愤怒\n"
		"悔恨之色。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2500);
	set("max_qi", 2500);
	set("jiali", 80);

	set("combat_exp", 250000);
	set("shen_type", 1);
	set("score", 50000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xuehua" :),
		(: perform_action, "sword.wanmei" :),
		(: perform_action, "sword.fengxue" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 100);
	set_skill("sword", 100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 100);
	set_skill("snow-strike", 150);
	set_skill("snowstep", 150);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 25)
	{
		command("say 你这种资质，怎能跟我学剑！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 50 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query_skill("xueshan-sword",1) < 50 )
	{ 
		command("say 你的本门剑法太低了，还是先找你师父提高吧！");
		return;
	}
	if ((int)ob->query("shen") < 10000 )
	{
		command("say 学剑须先正身，你做到了吗？");
		return;
	} 
	if ((int)ob->query_skill("sword",1) < 50 )
	{
		command("say 你的基本剑法太低了，还是先提高基本功吧！");
		return; 
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
} 

