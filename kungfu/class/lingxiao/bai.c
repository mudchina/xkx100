// bai.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MANAGER;
inherit F_MASTER;

void create()
{
	set_name("白自在",({"bai zizai","bai"}));
	set("nickname", HIC"威德先生"NOR);
	set("gender", "男性");
	set("age", 55);
	set("long", 
		"他就是雪山剑派的掌门人，习武成性，自认为天下武功第一，\n"
		"他大约五十多岁，精明能干，嫉恶如仇，性如烈火。\n");
	set("attitude", "peaceful");

	set("str", 35);
	set("con", 35);
	set("int", 30);
	set("dex", 30);
	set("per", 25);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("qi", 5000);
	set("max_qi", 5000);
	set("jiali", 100);
	set("inquiry", ([
		"石中玉" : "如果让我逮到这个小王八蛋，我非剥了他的皮不可。",
	]) );

	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 100000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xuehua" :),
		(: perform_action, "sword.wanmei" :),
		(: perform_action, "sword.fengxue" :),
		(: exert_function, "powerup" :),
		(: exert_function, "renegerate" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 300);
	set_skill("bingxue-xinfa", 200);
	set_skill("snow-strike", 300);
	set_skill("snowstep", 300);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");
	create_family("凌霄城", 5, "掌门");
	setup();

	carry_object("/d/lingxiao/obj/icesword")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30)
	{
		command("say 你这种资质，也好意思来找我！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 80 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query("shen") < 50000 )
	{
		command("say 我威德先生乃堂堂正人君子，怎能收你。"); 
		return;
	} 
	if ((int)ob->query("max_neili") < 800 )
	{
		command("say 你内力不足，怎能领悟我神功的精妙。"); 
		return;
	}
	if ((int)ob->query_skill("xueshan-sword",1) < 100 )
	{ 
		command("say 你的本门剑法太低了，还是先找你师父提高吧！");
		return;
	}
	if ((int)ob->query_skill("sword",1) < 100 )
	{
		command("say 你的基本剑法太低了，还是先提高基本功吧！");
		return; 
	}
	command("say 很好，很好,老子今天心情好，就收下你吧。");
	command("say 这个城老子没心情管了，你就先帮我管着吧。");
	command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) 
	ob->set("title", HIW"凌霄城城主"NOR); 
}

