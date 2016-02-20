// gong.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("黄钟公", ({ "huangzhong gong", "gong" }));
	set("long",
		"他就是梅庄四位庄主排行第一的黄钟公。\n"
		"身穿一件干干净净的黄色长袍。\n"
		"他已年愈六旬，身材中等，面容和蔼可亲。\n");
	set("gender", "男性");
	set("age", 62);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("env/wimpy", 40);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("luteplaying", 100);      // 绕梁琴艺
	set_skill("literate", 100);         // 读书识字
	set_skill("force", 150);            // 基本内功
	set_skill("unarmed", 150);          // 基本拳脚
	set_skill("dodge", 150);            // 基本躲闪
	set_skill("parry", 150);            // 基本招架
	set_skill("sword", 150);            // 基本剑法
	set_skill("piaoyibu", 200);         // 飘逸步法
	set_skill("wuyun-jian", 200);       // 五韵七弦剑
	set_skill("kuihua-xinfa", 150);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "wuyun-jian");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jian");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIY"梅庄大庄主"NOR);
	create_family("黑木崖", 9, "弟子");
	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/qin");
		if ( ob->violate_unique())
		{
      destruct(ob);
      ob=new(WEAPON_DIR"changjian");
    }
     	ob->move(this_object());
     	ob->wield();
  }
	carry_object("clone/cloth/male-cloth")->wear();
	carry_object("/d/meizhuang/obj/yaoshi1");
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 120)
	{
		command("say 我是不轻易收徒的。");
		command("say 在我教的内功上，" + RANK_D->query_respect(ob) +
			"是否还应该多下点功夫？");
		return;
	}
	command("say 好吧，老夫就收下你了。");
	command("recruit " + ob->query("id"));
}

