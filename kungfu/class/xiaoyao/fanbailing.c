// fanbailing.c 范百龄
// Modified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string ask_me();

void create()
{
	set_name("范百龄", ({ "fan bailing", "fan" }));
	set("long", "他师从聪辩先生，学的是围棋，当今天下，少有敌手。\n");
	set("nickname","“函谷八友”棋魔");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

	set("inquiry", ([
		"棋谱":(:ask_me:),
	]) );
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 60);
	set("combat_exp", 380000);
	set("score", 50000);

	set_skill("goplaying",150);
	set_skill("blade", 90);
	set_skill("ruyi-dao", 130);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("strike", 90);
	set_skill("parry", 90);
	set_skill("lingboweibu", 130);
	set_skill("beiming-shengong",90);
	set_skill("liuyang-zhang", 130);

	map_skill("strike", "liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("strike", "liuyang-zhang");
	set("book_count", 1);
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
	
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me,ob;
	ob=this_player(); 
	if (query("book_count") < 1)
		return "你来晚了，棋谱我已经赠送给别入了。";   

	add("book_count", -1);                  
	command("say 好吧，那我就把它送给你了。\n");
	message_vision(HIY"范百龄微笑着从怀中拿出了一本书，交了给$N\n\n"NOR,ob);
	me=new("/clone/book/hand_book");
	me->move(ob);
	return "这本棋谱可千万不要随便给别人。\n";
}
