// suxinghe.c 苏星河
// Modified by Winder June.25 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_me();
string ask_book();

void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("no_clean_up",1);

	set("long",
"此人就是号称聪辩老人的苏星河，据说他能言善辩， \n"
"是一个武林中的智者，而他的武功也是无人能知。\n");

	set("combat_exp", 3000000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"秘密地道" :(:ask_me:),
		"秘籍"     :(:ask_book:),
	]) );

	set("max_qi", 3400);
	set("max_jing", 400);
	set("neili", 3500);
	set("max_neili",3500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("dodge", 150);
	set_skill("hand", 150);
	set_skill("strike", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
        set_skill("force", 150);
	set_skill("lingboweibu", 220);
	set_skill("beiming-shengong", 150);
	set_skill("ruyi-dao", 220);
	set_skill("liuyang-zhang", 220);
	set_skill("zhemei-shou", 220);
	set_skill("literate", 100);
	set_skill("luteplaying", 150);
	set_skill("goplaying", 150);
	set_skill("literate", 100);
	set_skill("painting", 150);
	set_skill("medicine", 150);
	set_skill("construction", 150);
	set_skill("horticulture", 150);
	set_skill("dramaturgy", 150);
	map_skill("hand", "zhemei-shou");
	map_skill("strike", "liuyang-zhang");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("parry", "ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );	

	create_family("逍遥派", 2, "掌门");
	set("title","逍遥派第二代大弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void init()
{

  add_action("do_qiecuo","qiecuo");

}

void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在学问上多下点功夫？");
		return;
	}

	command("say 好吧，我就收下你了，今后要多加努力啊！");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要秘籍就得加入逍遥派。";
	}
	command("sigh");
	return"本派的武功秘籍藏在一个很秘密的地方，我也没去过。";
}
string ask_me()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "逍遥派")
	{
		return"想要知道密道就得加入逍遥派。";
	}
	command("sigh");
	return"本派的密道在云南无量山之上，很是艰险。你有兴趣可以去看看。";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
}
