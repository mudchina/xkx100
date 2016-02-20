// lu.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_join(string arg);
string ask_me();
string ask_huang();

void create()
{
	set_name("陆高轩", ({ "lu gaoxuan", "lu" ,"gaoxuan"}));
	set("nickname",HIC "神机妙算" NOR);
	set("long","他四十来岁年纪，文士打扮，天庭饱满，地阔方圆，容貌颇为英俊，神情和蔼可亲。然而满面愁容，恰似顷刻间便有杀身之祸一般。\n" );
	set("gender", "男性");
	set("age", 37);
	set("str", 35);
	set("dex", 20);
	set("max_qi",1500);
	set("qi",1500);
	set("max_jing",500);
	set("jing",500);
	set("combat_exp", 300000);
	set("score", 40000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("dulong-dafa", 70);
	set_skill("dodge", 70);
	set_skill("yixingbu", 70);
	set_skill("hand", 70);
	set_skill("shenlong-bashi", 100);
	set_skill("parry", 70);
	set_skill("hook", 70);
	set_skill("ruyi-hook", 100);
	set_skill("literate", 70);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("parry", "shenlong-bashi");
	map_skill("hook", "ruyi-hook");
	prepare_skill("hand", "shenlong-bashi");
	set("env/wimpy", 60);
	set("party/party_name", HIY"神龙教"NOR);
	set("party/rank", "军师");
	set("party/level", 2);
	create_family("神龙教", 2, "弟子");

	set_temp("apply/damage", 60);
	set("book_count", 1);
	set("neili", 1000); 
	set("max_neili", 1000);
	set("jiali", 100);
	set("inquiry", ([
		"洪安通" : "这三个字是你说的吗？",
		"洪教主" : "洪教主仙福永享，寿与天齐，洪教主神目如电，烛照四方。",
		"苏荃"   : "没规没矩的。",
		"神龙岛" : "神龙岛在汝州的东北方向，从塘沽口出海便到。",
		"神龙教" : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教"   : "一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"教主"   : "教主脾气不好，要讨他欢心才好。\n",
		"口号"   : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
		"秘籍"   : (: ask_me :),
		"book"   : (: ask_me :),
		"雄黄"   : (: ask_huang :),
		"huang"  : (: ask_huang :),
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(__DIR__"obj/shenlongci")->wield();
	add_money("silver", 10);
}

void init()
{
	add_action("do_join","join");
}

void attempt_apprentice(object ob)
{
	if (ob->query("party/party_name") != HIY "神龙教" NOR ) {
		command("say 你不是本教教众，想来找死啊！");
		return;
	}
	if ((int)ob->query_skill("literate",1) < 40 ) {
		command("say 你的学问太低了，还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -0 ) {
		command( "say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "神龙教")
		return RANK_D->query_respect(this_player()) + "与本教素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本教的秘籍不在此处。";
	add("book_count", -1);
	if (random(2) == 0) ob = new("/clone/book/shoufa");
	else ob = new("/clone/book/bufa");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到"+ob->query("name")+"啦。\n");
	return "好吧，这本「"+ob->query("name")+"」你拿回去好好钻研。";
}

string ask_huang()
{
	mapping fam; 
	object ob, me = this_player();

	if (!(fam = me->query("family")) ||
		fam["family_name"] != "神龙教")
		return RANK_D->query_respect(me) + "与本教素无来往，不知此话从何谈起？";
	if( present("xionghuang", me) )
		return RANK_D->query_respect(me)+"你现在身上不是雄黄吗，怎么又来要了？真是贪得无餍！";
	if( time() < me->query("huang/time") + 1800 )
		return RANK_D->query_respect(me) + "你不是刚要过雄黄，怎么又来要了？过段时间再来吧。";

	me->set("huang/time", time()); 
	ob = new(VEGETABLE_DIR"xionghuang");
	ob->move(me);
	return "好吧，这雄黄你就拿去吧。";
}
#include "/kungfu/class/shenlong/shenlong.h"; 
