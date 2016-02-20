// dujie.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("渡劫", ({ "du jie", "jie" }) );
	set("title", "少林长老");
	set("gender", "男性");
	set("age", 90);
	set("long",
		"这是一个面颊深陷，瘦骨零丁的老僧，他脸色惨白，象一张纸一样。\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 1500000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("dex", 30);
	set("con", 30);
	set("no_get", 1);

	set("qi", 4000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("jiali", 90);

	create_family("少林派", 35, "弟子");
	assign_apprentice("弟子", 0);

	set_skill("force", 150);
	set_skill("whip", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 250);
	set_skill("shaolin-shenfa", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 220);
	set_skill("cibei-dao", 220);
	set_skill("damo-jian", 220);
	set_skill("fengyun-shou", 220);
	set_skill("fumo-jian", 220);
	set_skill("jingang-quan", 220);
	set_skill("longzhua-gong", 220);
	set_skill("luohan-quan", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("pudu-zhang", 220);
	set_skill("qianye-shou", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("weituo-gun", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("xiuluo-dao", 220);
	set_skill("yingzhua-gong", 220);
	set_skill("yizhi-chan", 220);
	set_skill("zui-gun", 220);

	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

	set("inquiry", ([
		"金刚罩"     : (: ask_me :),
	]));
		
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("count", random(10)-8);

	setup();

	carry_object("/d/shaolin/obj/heisuo")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me)&&file_name(environment(me))=="/d/shaolin/fumoquan" ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] == 36 ) return;

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "少林派" 
		&& fam["generation"] > 36 		
		&& me->query("qi") < 50 ) 
		{
			me->move("/d/shaolin/qyping");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say 大胆鼠辈，乳臭未干，竟敢偷入金刚伏魔圈，且让老衲来超度与你！");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("jingang zhao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在你身上，真是贪得无餍！";

	if ( present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"宝罩只有一件，而且就在这里任你取走，真是贪得无餍！";

	if ( present("fumo dao", this_player()) || present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"取了伏魔刀，就不能再拿金刚罩，莫要贪得无餍！";

	if (query("count") < 1)
		return "抱歉，你来晚了，金刚罩已经给人取走了。";

//	ob = new("/d/shaolin/obj/jingang-zhao");
	ob = new(ARMOR_DIR"treasure/jingang-zhao");
	add("count", -1);
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return "抱歉，你来晚了，金刚罩已经给人取走了。";
	}

	ob->move(this_player());


	message_vision("\n渡劫一声不吭地瞧了$N半饷，扭过身，从树洞里取出金刚罩递给$N。\n\n", this_player());

	return "你能挨我们三个老不死的三招日月神鞭不死，确实是命大，这件金刚罩就是你的了！";
}
#include "/kungfu/class/shaolin/du.h"
