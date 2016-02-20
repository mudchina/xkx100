// zhang.c 张三丰

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_zhenwu();

void create()
{
	object ob;
	set_name("张三丰", ({ "zhang sanfeng", "zhang" }));
	set("nickname", "邋遢真人");
	set("long", 
"他就是武当派开山鼻祖、当今武林的泰山北斗，中华武功承先启
后、继往开来的大宗师。他以自悟的拳理、道家冲虚圆通之道和
九阳真经中所载的内功相发明，创出了辉映后世、照耀千古的武
当一派武功。此后他北游宝鸣，见到三峰挺秀，卓立云海，于武
学又有所悟，乃自号三丰。
身穿一件污秽的灰色道袍，不修边幅。身材高大，年满百岁，满
脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("combat_exp", 3000000);
	set("score", 500000);
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: perform_action, "parry.ren" :),
		(: perform_action, "unarmed.zhen" :),
		(: perform_action, "unarmed.ji" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 300);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 300);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 300);
	set_skill("liangyi-jian", 200);
	set_skill("wudang-jian", 300);
	set_skill("wudang-quan", 300);
	set_skill("taoism", 150);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	set("inquiry", ([
		"秘籍" : (: ask_me :),
		"真武剑" : (: ask_zhenwu : ),
	]));
	set("book_count", 1);
	create_family("武当派", 1, "开山祖师");
	set("class", "taoist");

	setup();
	if (clonep())
	{
		ob=new(WEAPON_DIR"treasure/zhenwu-jian");
		if ( ob->violate_unique())
      destruct(ob);
    else
      {
      	ob->move(this_object());
      	ob->wield();
    	}      
	}
	carry_object(CLOTH_DIR"dao-cloth")->wear();
	carry_object(CLOTH_DIR"dao-shoe")->wear();
}
void init()
{
	object ob;
	mapping myfam;

	::init();
	if (interactive(ob=this_player()) && ob->query("family"))
	{
		if (ob->query("family/master_id") == "zhang sanfeng" &&
			ob->query("shen") < -100 )
		{
			command("say "+RANK_D->query_rude(ob)+ "胆敢瞒着我在外胡作非为！\n");
			command("expell " + ob->query("id"));
			add_action("do_qiecuo","qiecuo");
			return;
		}
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "武当派")&&(!ob->query_skill("taiji-shengong",1))&&(ob->query("combat_exp")>500000))
       		{
                command("say 你竟敢放弃本门心法！从我这里滚出去吧！");
                command("expell " + ob->query("id"));
        	}
	add_action("do_qiecuo","qiecuo");
	}
	
	add_action("do_qiecuo","qiecuo");
}

string ask_zhenwu()
{
	object player = this_player();

	if( !player->query("wudang/zhenwu") )
		return "「真武剑」是贫道早年时所用的兵刃。";
}
void attempt_apprentice(object ob)
{
	mapping fam;

	if( mapp(fam = ob->query("family")) && fam["family_name"] != "武当派" )
	{
		command ("say " + RANK_D->query_respect(this_player()) + "并非我门中人，习武还是先从各位道长起吧！");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + "是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 80)
	{
		command("say 我武当派乃道家武功，高深的武功离不开道学心法。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该多读读道德经？");
		return;
	}
	if ((int)ob->query("shen") < 200000)
	{
		command( "say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30)
	{
		command( "say 我武当派武功全从道藏悟出。");
		command( "say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得" + ob->name() + "这么一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的武功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/taiji-book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到太极拳经啦。\n");
	return "好吧，这本「太极拳经」你拿回去好好钻研。";
}

