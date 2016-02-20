// xu.c
#include <ansi.h>
inherit NPC;

int ask_gao();

void create()
{
	set_name("许雪亭", ( { "xu xueting", "xu" }) );
	set("nickname", HIR "热血神龙" NOR);
	set("gender", "男性" );
	set("age", 55);
	set("long", "这是个五十来岁的高瘦汉子，着一袭青衣，目光炯炯，昂然挺立，看上去十分干练。\n");

	set("int", 30);
	set("str", 25);
	set("con", 23);
	set("dex", 22);
	
	set("qi",3000);
	set("max_qi", 3000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 150);
	set("combat_exp", 500000);
	set("score", 250000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("hand", 90);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taoism", 150);
	set_skill("literate", 60);
	set_skill("yixingbu", 80);
	set_skill("shenlong-bashi", 120);
	set_skill("taiji-jian", 120);
	set_skill("dulong-dafa", 100);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("sword", "taiji-jian");
	prepare_skill("hand", "shenlong-bashi");
	set("env/wimpy", 60);
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", HIR"青龙门"NOR"掌门使");
	set("party/level", 2);
	create_family("神龙教", 2, "弟子");

	set("inquiry", ([
		"百花腹蛇膏" : (: ask_gao :),
		"洪安通" : "这三个字是你说的吗？",
		"洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
		"苏荃"   : "没规没矩的。",
		"神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"教主"   : "教主脾气不好，要讨他欢心才好。\n",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	set("chat_chance", 3);
	set("chat_msg", ({
		"许雪亭忽然一怕脑袋，说：对了，可以用百花腹蛇膏！\n",
		"许雪亭怒道：唉，偌大一个神龙教，都毁在一个娘们手里了！\n",
		"许雪亭叹口气，说道：唉，不杀了洪安通，谁也活不了。\n",
	}) );
	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object("/d/shenlong/npc/obj/gcloth")->wear();
}

int ask_gao()
{
	say( "\n许雪亭悄声对你说：这可是本教禁物啊。它一遇鲜血，便生浓香，\n我们住在这灵蛇岛上，人人都服惯了雄黄酒，以避毒蛇，这股香气\n一碰到雄黄酒，便使人筋骨酥软，不能动弹。对了，你怎么也知道？\n");
	return 1;
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if ( (string)ob->query("name") != "腹蛇胆" &&
		(string)ob->query("name") != HIG "百香花" NOR )
		return notify_fail("许雪亭摇头道：如果杀不了洪安通，给我什么也没用啊。。。\n");
	if ( (string)ob->query("name") == "腹蛇胆" )
	{
		if(query_temp("baixianghua"))
		{
			message_vision("\n许雪亭见是腹蛇胆，大喜道：腹蛇胆百香花都有了，百花腹蛇膏练成了！\n",who);
			obn=new("/d/shenlong/obj/baihua");
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("fushedan"))
			{
				message_vision("\n许雪亭见是腹蛇胆，对$N摇头道：腹蛇胆我有了，就差百香花了。\n",who);
				return 0;
			}
			else
			{
				message("vision","许雪亭看见腹蛇胆，大喜道：有了腹蛇胆，只差百香花了。\n",environment(who));
				set_temp("fushedan",1);	
				return 1;
			}
		}
	}
	if ( (string)ob->query("name") == HIG "百香花" NOR)
	{
		if(query_temp("fushedan"))
		{
			message_vision("\n许雪亭见是百香花，大喜道：腹蛇胆百香花都有了，百花腹蛇膏练成了！\n",who);
			obn=new("/d/shenlong/obj/baihua");
			obn->move(who);
			delete_temp("fushedan");
			delete_temp("baixianghua");
			return 1;		 
		} 		
		else	
		{	
			if(query_temp("baixianghua"))
			{
				message_vision("\n许雪亭见是百香花，对$N摇头道：百香花我有了，就差腹蛇胆了。\n",who);
				return 0;
			}
			else
			{
				message("vision","许雪亭看见百香花，大喜道：有了百香花，只差腹蛇胆了。\n",environment(who));
				set_temp("baixianghua",1);	
				return 1;
			}
		}	
	}
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒！");
	return;
}
