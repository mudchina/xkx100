// weng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("秃笔翁", ({ "tubi weng", "weng" }));
        set("long",
                "他就是梅庄四位庄主排行第三的秃笔翁。\n"
                "身穿一件干干净净的白色长袍。\n"
                "他已年愈五旬，身材矮小，顶上光光, 一看就知道是个极易动怒的人。\n");
        set("gender", "男性");
        set("age", 52);
        set("class", "scholar");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("env/wimpy", 40);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("max_jing", 1400);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 80);
        set("combat_exp", 1000000);
        set("shen", 15000);
        set("score", 60000);

	set_skill("literate", 100);         // 读书识字
	set_skill("force", 100);            // 基本内功
	set_skill("dodge", 100);            // 基本躲闪
	set_skill("parry", 100);            // 基本招架
	set_skill("dagger", 100);           // 基本刺法
  set_skill("shigu-bifa", 150);       // 石鼓打穴笔法
	set_skill("staff",100);             // 基本杖法
  set_skill("jiangjun-zhang",150);    // 裴将军诗杖法
  set_skill("piaoyibu", 150);         // 飘逸步法
	set_skill("kuihua-xinfa", 100);	    // 葵花心法
  set_skill("xuantian-zhi",100);

	map_skill("force", "kuihua-xinfa");
	map_skill("dagger", "shigu-bifa");
        map_skill("dodge", "piaoyibu");
        map_skill("staff", "jiangjun-zhang");
        map_skill("parry", "shigu-bifa");
	prepare_skill("finger", "xuantian-zhi");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", WHT"梅庄三庄主"NOR);
        create_family("黑木崖", 9, "弟子");

        setup();
        carry_object("/d/meizhuang/npc/obj/panguan-bi")->wield();
        carry_object("/d/mingjiao/obj/baipao")->wield();
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂长老入教去！\n");
		return;
	}
        if ((int)ob->query_skill("kuihua-xinfa",1) < 60)
	{
                command("say 要百尺竿头更进一步，" + RANK_D->query_respect(ob) + "是否还在我教的内功上多下点功夫？");
                return;
        }
        command("say 好吧，老夫就收下你了。");
        command("recruit " + ob->query("id"));
}

