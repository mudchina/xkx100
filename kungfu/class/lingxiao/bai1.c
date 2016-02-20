// Last Modified by winder on Jul. 15 2001
// bai-wanjian.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("白万剑",({"bai wanjian","bai"}));
	set("nickname", HIC"气寒西北"NOR);
	set("gender", "男性");
	set("age", 30);
	set("long", 
		"白万剑是雪山派掌门人威德先生白自在的长子，他\n"
		"们师兄弟均以“万”字排行，他名字居然叫到白万剑，\n"
		"足见剑法之高。他外号气寒西北，与‘风火神龙’封万\n"
		"里合称‘雪山双杰’。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("per", 30);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 80);

	set("combat_exp", 1500000);
	set("score", 50000);
	set("inquiry", ([
		"白自在" : "老爷子的台讳是你叫的吗！",
		"老爷子" : "你想拜见老爷子吗？但他闭关面壁，你得找成师叔要到玉牌，才能见到他。",
		"掌门"   : "你想拜见老爷子吗？但他闭关面壁，你得找成师叔要到玉牌，才能见到他。",
		"玉牌"   : "寒玉牌乃我门中重宝，只有凭它，才能进入监狱。",
	]));
	set("shen_type", 1);

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
	set_skill("force", 120);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("literate", 100);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 120);
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
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/baihong-jian");
		if ( ob->violate_unique())
		 {
		 	destruct(ob);
		 	ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	}
	carry_object("/clone/money/gold");
	carry_object(CLOTH_DIR+"bai")->wear();
}
void attempt_apprentice(object ob)
{
	if (ob->query_int() < 28)
	{
		command("say 你这种资质，怎能跟我学剑！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 60 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query_skill("xueshan-sword",1) < 80 )
	{
		command("say 你的本门剑法太低了，还是先找你师父提高吧！");
		return;
	}
	if ((int)ob->query_skill("sword",1) < 80 )
	{
		command("say 你的基本剑法太低了，还是先提高基本功吧！");
		return; 
	}
	if ((int)ob->query("shen") < 20000 )
	{
		command("say 学剑须先正身，你做到了吗?"); 
		return;
	} 
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
} 

