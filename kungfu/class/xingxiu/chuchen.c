// shihou.c 出尘子

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("出尘子", ({ "chuchen zi", "chuchen", "zi" }));
	set("nickname", "星宿派八弟子");
	set("long", 
	"他身材虽矮，却是腰粗膀阔，横着看去，倒颇为雄伟，动作也甚敏捷。
手中握的钢杖又长又重。\n");
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 30);
	set("int", 15);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 15);
	set("combat_exp", 100000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("huagong-dafa", 4);
	set_skill("dodge", 60);
	set_skill("zhaixinggong", 50);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 70);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 70);
	set_skill("parry", 50);
	set_skill("staff", 80);
  	set_skill("tianshan-zhang", 80);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("no_get",1);
	set("env/wimpy", 60);
	set("inquiry", ([
		"星宿派" : "可惜老仙不准我收徒, 否则你可拜我为师。",
		"深涧"   : "问阿紫吧。",
		"吹捧"   : "小师妹最讨老仙喜欢, 你去问她吧。",
		"萧峰"   : "要不是那厮, 我早逮住了小师妹。",
		"老仙"   : "你得多吹捧老仙, 否则别想有出头之日。\n",
		"丁春秋" : "丁春秋是你叫的吗? 没大没小的。以后叫老仙! ",
		"星宿海" : "我现在很忙, 找别人带你去吧。",
		"杖法"   : "论天山杖法, 我最拿手。", 
		"天山杖法" : "你先练练基本功吧。",
		"基本功" : "找个山壁练。",
		"山壁"   : "还唠叨什么? 自己去找。",
		"神王木鼎" : "我可没提过, 再问我宰了你。",
		"山洞"   : "笨蛋, 把乱石推开不就可以进去了吗? ",
		"钢杖"   :    (: ask_me :),
	]) );
	set("zhang_count", 4);
	create_family("星宿派", 2, "弟子");
	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}

void do_killing(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	this_object()->kill_ob(ob);
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";

	if ( present("gangzhang", this_player()) )
		return RANK_D->query_respect(this_player()) + "你现在身上不是有钢杖吗，怎麽又来要了？ 真是贪得无餍！";

	if (query("zhang_count") < 1) return "对不起，钢杖已经发完了";
	ob = new("/clone/weapon/gangzhang");
	ob->move(this_player());
	add("zhang_count", -1);
	message_vision("$N获得一根钢杖。\n",this_player());
	return "记住，别丢掉了。";
}

void attempt_apprentice(object ob)
{
	command("say 老仙还没允许我收徒呢。");
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();

	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		((fam = ob->query("family")) && fam["family_name"] != "星宿派"))
	{
		command("say 大胆狂徒，竟敢闯到星宿海来偷宝！！！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
}
