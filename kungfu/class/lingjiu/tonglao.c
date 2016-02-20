// /NPC tonglao.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("天山童姥", ({ "tong lao", "tong", "lao" }));
	set("long",
		"她就是「灵鹫宫」的开山祖师。
乍一看似乎是个十七八岁的女子，可神情却是老气横秋。
双目如电，炯炯有神，向你瞧来时，自有一股凌人的威严。\n");
	set("title", "天山灵鹫宫主人");
	set("class", "dancer");
	set("gender", "女性");
	set("age", 96);
	set("nickname", HIR "唯我独尊" NOR);
	set("shen_type",0);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 35);
	set("con", 40);
	set("dex", 40);

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 200000);
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike", 200);
	set_skill("sword",200);
	set_skill("zhemei-shou",300);
	set_skill("liuyang-zhang",300);
	set_skill("tianyu-qijian",300);
	set_skill("yueying-wubu",300);
	set_skill("bahuang-gong", 250);
	set_skill("beiming-shengong",200);
	map_skill("force", "bahuang-gong");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword","tianyu-qijian");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_teach", ([
		"beiming-shengong" : "我这北冥神功乃是不传之学。",
	]));
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.san" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("逍遥派",1, "开山祖师");
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	if (random(2)==1)
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/food/jiudai");
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender")!="女性")
	{
		command("say 你找死啊！");
		return;
	}
	if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
	{
		command("say " + RANK_D->query_respect(ob) + "是否还应该多练练八荒六合唯我独尊功？");
		return;
	}
	if (ob->query_con() < 30) 
	{
		command("say 本门功法极为难练，你的根骨似乎不够。");
		return;
	}
	command("recruit " + ob->query("id"));
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
		if((string)ob->query("class") != "dancer")
			ob->set("class", "dancer");
		ob->set("title","灵鹫宫第二代弟子");
	}
}