// Npc: /kungfu/class/nanshaolin/fangji.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;

string ask_me_1();
string ask_me_2();
string ask_me_3();
void create()
{
	set_name("方济", ({ "fang ji", "fang", "ji"}));
	set("long", "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n");
	set("nickname", "药头");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("hand", 50);
	set_skill("fengyun-hand", 50);
	set_skill("qianye-hand", 50);
	set_skill("strike", 50);
	set_skill("weituo-strike", 50);
	set_skill("club", 50);
	set_skill("weituo-club", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("hand", "qianye-hand");
	map_skill("strike", "weituo-strike");
	map_skill("club", "weituo-club");
	map_skill("parry", "weituo-club");
	prepare_skill("hand", "qianye-hand");
	prepare_skill("strike", "weituo-strike");

	set("jin_count", 3);
	set("xiao_count",6);
	set("da_count", 6);
	set("inquiry", ([
		"金创药" : (: ask_me_1 :),
		"小还丹" : (: ask_me_2 :),
		"大还丹" : (: ask_me_3 :)
	]));
	create_family("南少林派", 21, "弟子");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"qimeigun")->wield();
}
string ask_me_1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";
	if ( present("jin chuangyao", this_player()) )
		return RANK_D->query_respect(this_player()) +"你现在身上不是有颗药丸吗，怎麽又来要了？ 真是贪得无餍！";
	if (query("jin_count") < 1) return "对不起，金创药已经发完了";
	ob = new(NOSTRUM_DIR+"jinchuang-yao");
	ob->move(this_player());
	add("jin_count", -1);
	message_vision("$N获得一包金创药。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";
}

string ask_me_2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) +"你是不是刚吃过药，怎麽又来要了？ 灵药多吃有害无宜，过段时间再来吧。";
	if ( present("xiaohuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) +"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";
	if (query("xiao_count") < 1) return "对不起，小还丹已经发完了";
	ob = new(NOSTRUM_DIR+"xiaohuan-dan");
	ob->move(this_player());
	add("xiao_count", -1);
	message_vision("$N获得一颗小还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";
}

string ask_me_3()
{
	mapping fam; 
	object me,ob;
	me = this_player();
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) +"你是不是刚吃过药，怎么又来要了？ 灵药多吃有害无宜，过段时间再来吧。";
	if ( (int)this_player()->query("max_neili" ) < 400)
		return RANK_D->query_respect(this_player()) +"功力不够，灵药多吃有害无宜，过段时间再来吧。";
	if ( present("dahuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) +"你现在身上不是有颗药丸吗，怎么又来要了？ 真是贪得无餍！";
	if ((int)me->query("max_neili") >= (int)me->query_skill("force")*10)
		return RANK_D->query_respect(this_player()) +"怎麽老想吃要呢，你武功已经不凡，去打坐提高修为吧。";
	if (query("da_count") < 1) return "对不起，大还丹已经发完了";
	ob = new(NOSTRUM_DIR+"dahuan-dan");
	ob->move(this_player());
	add("da_count", -1);
	message_vision("$N获得一颗大还丹。\n",this_player());
	return "好吧，记住，不到危急关头不要轻易使用此药。";
}
#include "/kungfu/class/nanshaolin/fang.h";
