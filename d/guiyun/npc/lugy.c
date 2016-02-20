// Npc: /d/guiyun/npc/lugy.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

// string ask_yao1();
string ask_yao2();

object ob = this_object();
void create()
{
	set_name("陆冠英", ({"lu guanying", "lu", "guanying"}) );
	set("long", "他身穿熟罗长袍，背厚膀宽，躯体壮健。\n");
	set("gender", "男性" );
	set("nickname", "归云庄少庄主" );
	set("age", 27);
	set("attitude", "peaceful");
//	set("apprentice",1);
	set("str",25);
	set("int",25);
	set("con",27);
	set("dex",26);
	set("max_qi", 1000);
	set("max_jing", 450);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 30);
	set("combat_exp", 70000);

	set_skill("force", 50);
	set_skill("bibo-shengong", 50);
	set_skill("dodge", 50);
	set_skill("anying-fuxiang", 40);
	set_skill("parry", 60);
	set_skill("strike", 40);
	set_skill("luoying-zhang", 35);
	set_skill("leg", 40);
	set_skill("xuanfeng-leg", 30);
	set_skill("sword", 60);
	set_skill("yuxiao-jian", 50);
	set_skill("taoism", 20);
	set_skill("literate", 60);
	set_skill("qimen-wuxing", 80);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "anying-fuxiang");
	map_skill("strike", "luoying-zhang");
	map_skill("leg", "xuanfeng-leg");
	map_skill("parry", "luoying-zhang");
	map_skill("sword", "yuxiao-jian");
	prepare_skill("strike", "luoying-zhang");

	set("rank_info/respect", "少庄主");
	set("shen_type", 1);
	set("shen", 200);
	create_family("桃花岛", 3, "弟子");
	set("class", "fighter");
	set("yao", 10);   

	set("inquiry", ([
		"name": "在下陆冠英，是这里的少庄主。",
		"rumors": "听说蒙古兵又要南侵了，唉！",
		"here": "这里是归云庄，你随便转转吧，累了请到客房休息。",
		"东邪": "那是师祖呀，，蒙他老人家恩准，我才能跟父亲学艺。",
		"黄药师": "那是师祖呀，，蒙他老人家恩准，我才能跟父亲学艺。",
		"桃花岛": "听说是师祖住的地方，可惜没有去看过。",
		"陆乘风": "是我的父亲，找他老人家有什么事吗？",
		"陆冠英": "不敢，就是在下。",
		"归云庄": "这里是花了我父亲无数心血才建起来的，与别的庄院相比如何？",
		"太湖": "就在庄前不远，是一个烟波浩淼的大湖。",
		"药" : "爹爹让我保管灵药，桃花岛弟子可以到我这里领取。",
//		"三才聚精丹": (: ask_yao1 :),
		"六壬集气丸": (: ask_yao2 :),
		"九花玉露丸": 	"九花玉露丸炼制奇难无比，我这里可没有! ",
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}

string ask_yao1()
{
	object ob = this_player();

	if (ob->query("family/family_name") != "桃花岛")
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if (ob->query_condition("jingli_drug") > 0 )
		return RANK_D->query_respect(ob) + "你不是刚吃过药吗，怎么又来要了？灵药多吃有害无宜，过段时间再来吧。";

	if (ob->query("max_jingli" ) < 200)
		return RANK_D->query_respect(ob) + "功力不够，灵药多吃有害无宜，过段时间再来吧。";

	if (present("sancai dan", ob))
		return RANK_D->query_respect(ob) + "你现在身上不是有颗药丸吗，怎么又来要了？真是贪得无厌！";

	if (query("yao") < 1) return "对不起，药已经发完了，新的还未炼出。";
   
	new("/d/taohua/obj/sancai-dan")->move(ob);

	add("yao", -1);

	message_vision("$N获得一颗三才聚精丹。\n", ob);
	return "好吧，此药练之不易，对练武之人大有好处，你要小心收藏好了。";
}

string ask_yao2()
{
	object ob = this_player();

	if (ob->query("family/family_name") != "桃花岛")
		return RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？";

	if (ob->query_condition("medicine") > 0 )
		return RANK_D->query_respect(ob) + "你不是刚吃过药吗，怎么又来要了？灵药多吃有害无宜，过段时间再来吧。";

	if (this_player()->query("max_neili") < 400)
		return RANK_D->query_respect(ob) + "功力不够，灵药多吃有害无宜，过段时间再来吧。";

	if (present("liuren wan", ob))
		return RANK_D->query_respect(ob) + "你现在身上不是有颗药丸吗，怎么又来要了？真是贪得无厌！";

	if (query("yao") < 1) return "对不起，药已经发完了，新的还未炼出。";

         if(ob->query("max_neili")>= (ob->query_skill("force")*8+ob->query("combat_exp",1)/1000))
                     return RANK_D->query_respect(ob) + "此药已经难以在帮助你提高内力修为了！";
	new("/clone/medicine/liuren-wan")->move(ob);

	add("yao", -1);

	message_vision("$N获得一颗六壬集气丸。\n", ob);
	return "好吧，此药练之不易，对练武之人大有好处，你要小心收藏好了。";
}


