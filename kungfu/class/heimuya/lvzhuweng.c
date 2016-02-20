// lvzhuweng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("绿竹翁", ({ "luzhu weng", "weng" }));
        set("long",
"他身子略形佝偻，头顶稀稀疏疏的已无多少头发，大手大脚，精神却十分矍铄。\n");
        set("gender", "男性");
        set("age", 62);
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
        set("combat_exp", 1200000);
        set("shen", 15000);
        set("score", 60000);

	set_skill("literate", 100);         // 读书识字
	set_skill("force", 100);            // 基本内功
	set_skill("dodge", 100);            // 基本躲闪
	set_skill("parry", 100);            // 基本招架
	set_skill("dagger", 100);           // 基本刺法
        set_skill("shigu-bifa", 100);       // 石鼓打穴笔法
	set_skill("piaoyibu", 100);         // 飘逸步法
	set_skill("kuihua-xinfa", 100);	    // 葵花心法

	map_skill("force", "kuihua-xinfa");
	map_skill("dagger", "shigu-bifa");
        map_skill("dodge", "piaoyibu");
        map_skill("parry", "shigu-bifa");

	set("inquiry", ([
		"日月神教" : "你想加入我日月神教，就得找四大堂长老。",
		"入教"     : "你想加入我日月神教，就得找四大堂长老。",
	]));

	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", "长老");
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
        if ((int)ob->query_skill("kuihua-xinfa",1) < 50)
	{
                command("say 要百尺竿头更进一步，" + RANK_D->query_respect(ob) + "是否还在我教的内功上多下点功夫？");
                return;
        }
        command("say 好吧，老夫就收下你了。");
        command("recruit " + ob->query("id"));
}

