// /kungfu/class/xueshan/xuedao.c  血刀老祖
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	object ob;

	set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
	set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
	);
	set("title",HIR"血刀门第四代掌门"NOR);
	set("gender", "男性");
	set("age", 85);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 3000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 3000000);
	set("score", 180000);

	set_skill("lamaism", 150);
	set_skill("literate", 80);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("sword", 200);
	set_skill("dodge", 200);
	set_skill("longxiang", 200);
	set_skill("shenkong-xing", 300);
	set_skill("hand", 200);
	set_skill("dashou-yin", 300);
	set_skill("mingwang-jian", 300);
	set_skill("xue-dao", 300);

	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");
	map_skill("sword", "mingwang-jian");
	prepare_skill("hand", "dashou-yin");
	set("chat_chance_combat", 80);  
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: exert_function, "shield" :),
		(: command("unwield flood blade") :),
		(: command("wield flood blade") :),
	}) );

	create_family("雪山寺", 4, "弟子");
	set("class", "lama");

	setup();
	 if (clonep())
	 {
	 	 ob=new(WEAPON_DIR"treasure/xblade");
	 	 if ( ob->violate_unique())
	 	  {
	 	  	destruct(ob);
	 	  	ob=new("/clone/weapon/blade");
 	  	}
 	  	ob->move(this_object());
 	  	ob->wield();
	 	}
  carry_object("/d/xueshan/obj/y-jiasha")->wear();
	add_money("gold",2);
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性")
	{
		command("say 我不收女徒弟。\n");
		return;
	}
	if ((string)ob->query("family/family_name") != "雪山寺")
	{
		command("say 这位" + RANK_D->query_respect(ob) +
			"既非本门弟子，还是请回吧！\n");
		return;
	}
	if ((int)ob->query("shen") > -100000)
	{
		command("say 你是不是向着侠义道，连杀人都不会！\n");
		return;
	}
	if ((int)ob->query_skill("longxiang", 1) < 60)
	{
		command("say 入我血刀门，修习龙象功法是首要的。\n");
		return;
	}
	command("haha");
	command("nod");
	command("recruit " + ob->query("id"));

	ob->set("title", HIR "血刀门第五代弟子" NOR);
}
