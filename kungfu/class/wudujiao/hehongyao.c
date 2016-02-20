// hehongyao.c
// 何红药
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ob;
	set_name("何红药", ({ "he hongyao", "he" }));
	set("nickname", HIG "疤面丐婆" NOR);
	set("long",@LONG
他就是五毒教的长老，教主的姑姑何红药。随然是教主的长辈，但功夫却是一块跟
上代教主学的。据说她曾经被立为教主继承人，但后来犯下大错，所以被罚到此处
看守圣地，以赎前罪。她穿着一身破旧的衣衫，满脸疤痕，长得骨瘦如柴，双目中
满是怨毒之色。
LONG
	);
	set("title","五毒教长老");
	set("class", "beggar");
	set("gender", "女性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("per", 10);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 500000);

	set_skill("force", 200);
	set_skill("wudu-shengong", 200);
	set_skill("dodge", 190);
	set_skill("wudu-yanluobu", 250);
	set_skill("hand", 160);
	set_skill("qianzhu-wandushou", 220);
	set_skill("strike", 160);
	set_skill("wudu-zhang", 220);
	set_skill("parry", 180);
	set_skill("hook", 200);
	set_skill("wudu-goufa", 300);
	set_skill("sword", 200);
	set_skill("qingmang-sword", 300);
	set_skill("five-poison", 160);
	set_skill("literate", 80);

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


	create_family("五毒教", 11, "长老");
	setup();

	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/jiandao");
		if ( ob->violate_unique())
       destruct(ob);
    else
      {
      	ob->move(this_object());
        ob->wield();
      }
		}
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object("/clone/medicine/poison/wuxing");

	add_money("silver",30);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") == "无性")
	{
		command("say 这位公公不要开玩笑了。");
		command("say 这位" + RANK_D->query_respect(ob) +"还是快去伺候皇上吧！");
		return;
	}

	if ((int)ob->query("shen") > -10000)
	{
		command("say 做我五毒教弟子必须心狠手辣。");
		command("say 这位" + RANK_D->query_respect(ob) +"心慈手软，可惜与我教没有缘分啊！");
		return;
	}

	if ((string)ob->query("family/family_name") != "五毒教")
	{
		command("say 这位" + RANK_D->query_respect(ob) +"不是本教弟子，还是请回吧！");
		return;
	}

	if ((int)ob->query_skill("five-poison", 1) < 100)
	{
		command("say 我五毒教弟子以毒杀人，修习毒技是首要的。");
		command("say 这位" + RANK_D->query_respect(ob) + "是否还应该多多钻研本门的绝学？");
		return;
	}
	if ((int)ob->query_skill("wudu-shengong", 1) < 100)
	{
		command("say 你的五毒神功还学的不够啊。");
		return;
	}

	command("chat 嘿嘿嘿嘿！！！！！");
	command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");
	command("chat 嘿嘿嘿嘿！！！！！");
	command("recruit " + ob->query("id"));
	ob->set("title",HIY"五毒教护法"NOR);
	return;
}

