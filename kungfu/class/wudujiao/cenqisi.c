// cenqisi.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("岑其斯", ({ "cen qisi", "cen" }));
	set("nickname", HIG "五毒秀士" NOR);
	set("long",@LONG
他就是五毒教的右护法，人称五毒秀士的岑其斯。经常装扮成一个
白衣秀士的模样，没事总爱附庸风雅。
LONG
	);
	set("title","五毒教护法");
	set("gender", "男性");
	set("class", "shaman");
	set("age", 38);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 3000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 50000);

	set_skill("force", 120);
	set_skill("wudu-shengong", 120);
	set_skill("dodge", 130);
	set_skill("wudu-yanluobu", 180);
	set_skill("hand", 120);
	set_skill("qianzhu-wandushou", 180);
	set_skill("strike", 120);
	set_skill("wudu-zhang", 180);
	set_skill("parry", 120);
	set_skill("sword", 130);
	set_skill("qingmang-sword", 180);
	set_skill("hook", 130);
	set_skill("wudu-goufa", 180);
	set_skill("five-poison", 120);
	set_skill("literate", 100);

	map_skill("force", "wudu-shengong");
	map_skill("dodge", "wudu-yanluobu");
	map_skill("hand", "qianzhu-wandushou");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-goufa");
	map_skill("hook", "wudu-goufa");
	map_skill("sword", "qingmang-sword");
	prepare_skill("hand", "qianzhu-wandushou");
	prepare_skill("strike", "wudu-zhang");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "hook.suo" :),
		(: perform_action, "hand.qzwd" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("五毒教", 12, "护法");

	setup();
	carry_object("/d/wudujiao/npc/obj/ganggou")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
	carry_object(CLOTH_DIR"male-shoe")->wear();

	add_money("silver",20);
}

void attempt_apprentice(object ob)
{

	if ((string)ob->query("gender") == "无性")
	{
		command("say 这位公公不要开玩笑了。");
		command("say 这位"+RANK_D->query_respect(ob)+"还是快去伺候皇上吧！\n");
		return;
	}

	if ((int)ob->query("shen") > -5000)
	{
		command("say 做我五毒教弟子必须心狠手辣。");
		command("say 这位"+RANK_D->query_respect(ob)+"心慈手软，可惜与我教没有缘分啊！\n");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 这位" + RANK_D->query_respect(ob) + "不是本教弟子，还是请回吧！\n");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 60)
	{
		command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
		command("say 这位" + RANK_D->query_respect(ob)+"是否还应该多多钻研本门的绝学？\n");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 60)
	{
		command("say 你的五毒神功还学的不够啊。");
		return;
	}

//	command("chat 嘿嘿嘿嘿！！！！！");
//	command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
//	command("chat 嘿嘿嘿嘿！！！！！");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"五毒教弟子"NOR);
	return;
}

