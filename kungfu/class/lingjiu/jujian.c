// /NPC meijian.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void greeting(object);
void init();
void create()
{
	set_name("菊剑", ({ "ju jian", "ju"}));
	set("title", "灵鹫宫第三代弟子");
	set("long",
		"这是个容貌姣好的女子，瓜子脸蛋，眼如点漆，清秀绝俗。
你总觉得在哪见过她。\n");
	set("gender", "女性");
	set("class", "dancer");
	set("age", 18);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 50000);
	set("score", 10000);
	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("hand",70);
	set_skill("strike", 70);
	set_skill("sword",80);

	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("tianyu-qijian",120);
	set_skill("yueying-wubu",120);
	set_skill("bahuang-gong", 80);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );		

	create_family("逍遥派",3,"弟子");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/food/jiudai");
	add_money("silver",15);
}

void init()
{
	object ob;
 
	::init();
 
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if (objectp(ob) && environment(ob)==environment(this_object()))
	if ((string)ob->query("family/family_name") == "灵鹫宫") 
	{
		message_vision("菊剑冲着$N点点头，微微笑了笑。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender")=="女性")
	{
		message_vision("菊剑垂目沉思片刻, 说道：“好吧, 我就收下你了。”\n",ob);
		command("recruit " + ob->query("id"));
//		if((string)ob->query("class") != "dancer")
//			ob->set("class", "dancer");
		return;
	}
	else
	{
		message_vision("菊剑瞪着你看了半天, 娇嗔道：“你一个大男人，跑这里来学功夫，羞也不羞。”\n",ob);
		return;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","灵鹫宫第四代弟子");
	}
}