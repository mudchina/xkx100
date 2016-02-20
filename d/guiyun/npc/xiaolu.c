// xiaolu.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("陆冠英", ({ "lu guanying", "lu" }));
	set("long", "
他是归云庄少庄主陆冠英。他肩宽背阔，躯体甚是壮健，
但行动之间温文尔雅，谦恭有礼，一派世家子弟风范。
传闻他就是太湖群盗的首领，不知是真是假。\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 26);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 600);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);
	set("combat_exp", 150000);
	set("score", 6000);

	set_skill("force", 50);
	set_skill("bibo-shengong", 50);
	set_skill("dodge", 50);
	set_skill("anying-fuxiang", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("yuxiao-jian", 50);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("sword", "yuxiao-jian");
	map_skill("parry", "yuxiao-jian");

	set("inquiry", ([
		"归云庄" : (: ask_me :),
	]));

	set("book_count", 1);
        create_family("桃花岛", 3, "弟子 归云庄少庄主");
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

init()
{
	add_action("do_decide", "decide");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say 我派武功讲究轻灵巧捷。");
           command("say 这位"+RANK_D->query_respect(ob)+"可能是白来归云庄一趟了。");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"请回吧。");
           return;
        }
        if (ob->query("gender") == "无性")
        {
           command("say 师祖最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say 师祖最爱非僧抑道了，这位"+RANK_D->query_respect(ob)+"还是请回吧。");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
        command("recruit " + ob->query("id"));
}


string ask_me()
{
	object me = this_player();
	me->set_temp("guiyun/decide",1);

        if((string)me->query("family/family_name") != "桃花岛")
	   return "归云庄就是在下居处，如果"+RANK_D->query_respect(me)+"有意(decide)，我可修书一封代为引荐。\n";
        command("say 这位"+ RANK_D->query_respect(me)
	       + "来得正好，这里正有马车要回庄办事，就让他们送你一程吧。\n");
//      message_vision(HIC"陆冠英一招手，一辆马车驶过来停在门前。\n$N急忙钻进车中，只听一阵清脆的鞭响，马车绝尘而去。\n\n"NOR,me);
//	ob = load_object("/d/guiyun/dayuan");
//	ob = find_object("/d/guiyun/dayuan");
//	message("vision", "远处一辆马车急驶而来，车门一开"+me->query("name")+"从里面钻了出来。\n", ob);
//    	tell_object(me, "只听车把势说道：这位"+ RANK_D->query_respect(me) + "已经到了，请下车吧。\n"NOR );
	me->move("/d/guiyun/dayuan");           
}

int do_decide()
{
	object ob, me;
	me = this_player();
	if (!me->query_temp("guiyun/decide"))
	{
		message_vision("$N对$n奇怪地说道：你要决定干嘛？\n", this_object(), me);
		return 1;
	}
	me->delete_temp("guiyun/decide");
	ob = new(__DIR__"obj/xin");
	ob->move(me);
	message_vision("$N双手抱拳，道：有劳少庄主费心了。\n", me);
	message_vision("$N说道：好！\n", this_object());
	message_vision("$N给$n一封书信。\n", this_object(), me);
	message_vision("$N说道：这位"+RANK_D->query_respect(me) + "请先到敝庄盘恒数日，以后再图相叙。\n", this_object());
	return 1;
}
