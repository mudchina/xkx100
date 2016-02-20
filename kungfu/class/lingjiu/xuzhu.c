// /NPC xuzhu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("虚竹", ({ "xu zhu", "xu", "zhu" }));
	set("long",
		"这是一个二十五六岁的年轻人，浓眉大眼，大大的鼻子扁平下塌，容貌
颇为丑陋。身穿一件华贵雅致的长袍，倒使他更显几分精神。
他就是天山童姥的救命恩人。\n");
	set("title", "灵鹫宫第二代掌门人");
	set("gender", "男性");
	set("age", 26);
	set("nickname", HIR "梦郎" NOR);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 30);
	set("int", 25);
	set("con", 40);
	set("dex", 30);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 8000);
	set("max_neili", 8000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 20000);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("tianyu-qijian", 300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 200);
	set_skill("beiming-shengong",200);
	set_skill("hunyuan-yiqi",100);
	set_skill("shaolin-shenfa",100);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("sword", "tianyu-qijian");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
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
	set("no_teach", ([
		"beiming-shengong" : "唉……这是师尊注如我体内的，教我怎么教给你？",
                "hunyuan-yiqi"     : "…这…这东西我都没学好。",
                "shaolin-shenfa"   : "…这个…嗯…我还是教你本门的轻功好了。",
	]));
	create_family("逍遥派",2,"掌门");
	setup();
	carry_object("/d/lingjiu/obj/changpao")->wear();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/food/jiudai");
	add_money("silver",50);
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
	{
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	}  
	if ((string)ob->query("gender")=="女性")
	{
  	      command("nod");
  	      command("say 今日小僧…在下就收下你，以后你要多做好事。");
  	      command("say 另外，以后若遇到了少林寺的大师，可千万不能和他们为难。");
		command("recruit " + ob->query("id"));
		return;
	}
	else
	{
		message_vision("虚竹瞪着你看了半天,说道：“阁下不会是想来抢我的生意吧?”\n",ob);
		return;
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","灵鹫宫第三代弟子");
	}
}