// dongfang.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();

void create()
{
	object ob;
	set_name("东方不败", ({"dongfang bubai", "dongfang", "bubai", "dong"}));
	set("nickname", HIY "武功天下第一" NOR );
	set("gender", "无性");
	set("class", "eunach");
	set("shen_type", -1);
	set("age", 42);
	set("long", "他就是日月神教教主。据传武功天下第一，因此大号就是「东方不败」。\n");
	set("attitude", "peaceful");

	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
	set("no_get",1);

	set("chat_chance", 1);
	set("chat_msg", ({
		"东方不败叹了口气道：“唉 …… 我的杨大哥…他怎么还不回来，我好挂念他 ……东方不败眼中流露无限迷茫。\n",
	}));
	set("inquiry", ([
		"杨莲亭"   : "你敢直称我爱人的名字，想找死呀？ \n",
		"葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 400);

	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("literate", 100);         // 读书识字
	set_skill("force", 200);            // 基本内功
	set_skill("finger", 200);           // 基本指法
	set_skill("unarmed", 200);          // 基本拳脚
	set_skill("dodge", 200);            // 基本躲闪
	set_skill("parry", 200);            // 基本招架
	set_skill("dagger", 200);           // 基本刺法
	set_skill("sword", 200);            // 基本剑法
        set_skill("shigu-bifa", 300);       // 石鼓打穴笔法
	set_skill("piaoyibu", 300);         // 飘逸步法
	set_skill("bixie-jian", 250);       // 辟邪剑法
	set_skill("wuyun-jian", 300);       // 五韵七弦剑
	set_skill("xuantian-zhi", 300);	    // 玄天无情指
	set_skill("kuihua-xinfa", 200);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("sword", "bixie-jian");
	map_skill("dagger", "shigu-bifa");
	map_skill("finger", "xuantian-zhi");
	map_skill("dodge", "bixie-jian");
	map_skill("parry", "bixie-jian");

	prepare_skill("finger", "xuantian-zhi");

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIM"第八代教主"NOR);
	create_family("黑木崖", 8, "弟子");

	setup();
	if (clonep())
	 {
	 	ob=new(WEAPON_DIR"treasure/zhen");
	 	if ( ob->violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new(WEAPON_DIR"changjian");
	 	}
	 	ob->move(this_object());
	 	ob->wield();
	 }
  carry_object("/d/wanjiegu/npc/obj/qi-dress")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa",1) < 150)
	{
		command("say 在我教的内功上，" + RANK_D->query_respect(ob) + "是否还应该多下点功夫？");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 我不收资质差的弟子，您请回吧！\n");
		return;
	}
	if (ob->query("gender") != "无性" )
	{
		command("say 要练神功，必须自宫。");
		return;
	}
	if ((int)ob->query("shen") >100000 || (int)ob->query ("shen") < -100000)
	{
		command("say 我黑木崖与世隔绝，向来不与您这种成名人物打交道，您请回吧！\n");
		return;
	}
	command("say 很好，很好。\n");
	command("recruit " + ob->query("id"));
}

