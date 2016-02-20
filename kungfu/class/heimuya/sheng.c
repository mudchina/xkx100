// danqing-sheng.c 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("long",
		"他就是梅庄四位庄主排行第四的丹青生。\n"
		"身穿一件干干净净的青色长袍。\n"
		"他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
	set("gender", "男性");
	set("age", 41);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("env/wimpy", 40);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("shen", 15000);
	set("score", 60000);

	set_skill("painting", 100);         // 泼墨丹青
	set_skill("literate", 100);         // 读书识字
	set_skill("force", 80);             // 基本内功
	set_skill("dodge", 80);             // 基本躲闪
	set_skill("parry", 80);             // 基本招架
	set_skill("sword", 80);             // 基本剑法
	set_skill("piaoyibu", 120);          // 飘逸步法
	set_skill("pomopima-jian", 120);    // 泼墨披麻剑
	set_skill("kuihua-xinfa", 80);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "pomopima-jian");
	map_skill("sword", "pomopima-jian");

	set("inquiry", ([
		"令牌"     : (: ask_me :),
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	])); 
	set("item_count", 1);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIG"梅庄四庄主"NOR);
	create_family("黑木崖", 9, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
	if ((int)ob->query("shen") < 0)
	{
		command("say 本教虽不是什么名门正派，但在梅庄，择徒也极为严格。");
		command("say 在品行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，老夫就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "黑木崖")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (query("item_count") < 1)
		return "你来晚了，梅花令牌不在此处。";
	add("item_count", -1);
	ob = new("/d/meizhuang/npc/obj/lingpai");
	ob->move(this_player());
	return "好吧，这块梅花令牌就交给你保管了。";
}

