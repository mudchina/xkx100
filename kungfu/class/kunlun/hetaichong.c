// hetaichong.c
// Last Modified by Winder on Nov. 15 2000

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("何太冲", ({ "he taichong", "he" }));
	set("nickname", "铁琴先生");
	set("long",
		"他就是昆仑派掌门、名扬江湖的铁琴先生何太冲。\n"
		"虽然年纪已大，但仍然看得出他年轻时英俊潇洒。\n");
	set("gender", "男性");
	set("class", "taoist");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 40000);

	set_skill("literate", 100);
	set_skill("force", 100);
	set_skill("xuantian-wuji", 160);
	set_skill("dodge", 140);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 80);
	set_skill("kunlun-strike", 120);
	set_skill("parry", 165);
	set_skill("sword", 175);
	set_skill("liangyi-sword", 175);
	set_skill("xunlei-sword", 220);
	set_skill("mantian-huayu", 220);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-cuff", 160);
  set_skill("leg", 155);
	set_skill("chuanyun-leg", 160);

	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-cuff");
	map_skill("parry", "xunlei-sword");
	map_skill("sword", "xunlei-sword");
	map_skill("leg", "chuanyun-leg");
	prepare_skill("cuff", "zhentian-cuff");
	prepare_skill("leg", "chuanyun-leg");
	
	set("no_get",1);

	create_family("昆仑派", 4, "掌门人");
	set("class", "taoist");

	set("inquiry",
	([
		"心法" : (: ask_me :),
		"苏习之" : (: ask_su :),
		"追杀" : (: ask_ding :),
	]));

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/kunlun/obj/pao2")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
/*
	if((int)ob->query("shen")<0)
	{
		command("say 我昆仑乃是堂堂名门正派，"+RANK_D->query_respect(ob)+ "的品德实在令人怀疑。");
		command("say "+RANK_D->query_respect(ob)+
			"还是先回去做点善事吧。");
		return;
	}
*/
	if(ob->query("gender")=="女性")
	{
		command("fear");
		command("say "+RANK_D->query_respect(ob)+
			"老夫可不敢收女弟子，你去找我夫人去吧。");
		return;
	}

	if(ob->query("appren_hezudao", 1) == 1)
	{
		command("say 前辈怎敢开这等玩笑，真是折杀做晚辈的了。");
		return;
	}

	if(ob->query_skill("xuantian-wuji",1)<100)
	{
		command("hmm");
		command("say "+RANK_D->query_respect(ob)+
			"你的玄天无极功太差，我可不想收你。");
		return;
	}
	command("say 好吧，我便收下你，只是你投入我门下之后，须得安心学艺。");
	command("recruit " + ob->query("id"));
}


string ask_me()
{
	mapping fam;
	object ob;
        ob = this_player();
	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "昆仑派")
		return RANK_D->query_respect(this_player()) +
			"与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派心经已被你师兄拿走了。";
//     	if(ob->query("gender")=="男性"||ob->query("per")<23)
//		return "本派心经不在我这里。";
	add("book_count", -1);
	ob = new("/clone/book/force-book2");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到昆仑心法啦。\n");
	return "我这里有本「心法」，是有关吐呐吸气的，你拿回去好好钻研，有空多来找我哦！";
}

string ask_ding()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "昆仑派")
		return RANK_D->query_respect(this_player()) +
			"与本派素无来往，不知此话从何谈起？";
		
	if(this_player()->query_skill("mantian-huayu",1) < 60)
		return "你如此自愿为师门效力，不枉我平时一番栽培，速速去吧！";

	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
			"你现在身上不是有吗，怎么又来要了？";
	if (query("ding_count") < 1)
		return "丧门钉已给了我派去追杀苏习之的人，你就不用去了。";
	add("ding_count", -1);
	this_player()->set_temp("kunlun/ding",1);
	ob = new("/d/kunlun/obj/sangmending");
	ob->move(this_player());
	return "你如此自愿为师门效力，不枉我平时一番栽培，这把丧门钉你就拿去吧。";
}
string ask_su()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))
		|| fam["family_name"] != "昆仑派")
		return RANK_D->query_respect(this_player()) +
			"与本派素无来往，不知此话从何谈起？";
		
	if(this_player()->query_temp("kunlun/ding",1))
		return "你还待在这里做什么，还不快去追苏习之！";
	return "苏习之这家伙竟然敢偷看本派的两仪神剑，我派弟子必当将其追杀。";
}
