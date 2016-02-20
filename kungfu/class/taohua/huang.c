#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

void consider();
string ask_me();
string ask_yao();
string ask_gua();

void create()
{
	object ob;
	set_name("黄药师", ({"huang yaoshi", "huang", "yaoshi"}));
	set("title", "桃花岛主");
	set("nickname", HIY "东邪" NOR );
	set("gender", "男性");
	set("age", 42);
	set("long", 
		"他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
	set("attitude", "peaceful");
	set("class", "scholar");
	
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"黄药师叹了口气道：“唉 …… 蓉儿这苦命的孩子，从小就没了娘 ……”\n",
		"黄药师低头沉思，悠然不语。\n",
	}));
	set("inquiry", ([
		"黄蓉"         : "你敢直称我女儿的闺名？ \n",
		"九阴真经"     : "如果你能帮我取得真经上册，我一定重重谢你。\n",
		"九花玉露丸"   : "此丸配制不易，乘风那里可能还有吧。\n",
		"无常丹"       : (: ask_yao :),
		"铁八卦"       : (: ask_gua :),
		"秘籍"         : (: ask_me :),
		"旋风扫叶腿法" : (: ask_me :),
	]));

	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 3000);
	set("max_jing", 3000);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 100);

	set("book_count", 1);
	set("yao_count", 1);
	set("gua_count", 1);
	set("combat_exp", 3000000);
	set("score", 0);
	 
	set_skill("force", 200);		// 基本内功
	set_skill("bibo-shengong", 200);	// 碧波神功
	set_skill("claw", 200);			// 基本爪法
	set_skill("hand", 200);			// 基本手法
	set_skill("finger", 200);		// 基本指法
	set_skill("tanzhi-shentong", 300);	// 弹指神通
	set_skill("unarmed", 200);		// 基本拳脚
	set_skill("strike", 200);		// 基本拳脚
	set_skill("luoying-zhang", 300);	// 落英神剑掌
	set_skill("xuanfeng-leg", 300);		// 旋风扫叶腿
	set_skill("dodge", 200);		// 基本躲闪
	set_skill("anying-fuxiang", 300);	// 暗影浮香
	set_skill("parry", 200);		// 基本招架
	set_skill("sword", 200);		// 基本剑法
	set_skill("luoying-shenjian", 300);	// 落英神剑
	set_skill("yuxiao-jian", 300);		// 玉箫剑法
	set_skill("lanhua-shou", 300);		// 兰花拂穴手
	set_skill("qimen-wuxing",150);		// 奇门五行
	set_skill("array", 120);		// 基本阵法
	set_skill("count",150);			// 阴阳八卦
	set_skill("literate",150);		// 读书识字
	
	map_skill("force"  , "bibo-shengong");
	map_skill("finger" , "tanzhi-shentong");
	map_skill("hand"   , "lanhua-shou");
	map_skill("strike", "luoying-zhang");
	map_skill("unarmed" , "xuanfeng-leg");
	map_skill("dodge"  , "anying-fuxiang");
	map_skill("parry"  , "luoying-shenjian");
	map_skill("sword"  , "yuxiao-jian");
	prepare_skill("hand", "lanhua-shou");
	prepare_skill("finger", "tanzhi-shentong");
	
	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.tianwai" :),
		(: perform_action, "finger.jinglei" :),
		(: perform_action, "hand.fuxue" :),
		(: exert_function, "roar" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("桃花岛", 1, "岛主");
	setup();
	
	carry_object(__DIR__"obj/yuxiao")->wield();
	carry_object(__DIR__"obj/bupao")->wear();
//	carry_object("clone/book/jiuyin2");
  if (clonep())
  {
		ob = new("/clone/book/jiuyin2");
		if (ob->violate_unique())	destruct(ob);
		else ob->move(this_object());
	}
}

void init()
{
	add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if (ob->query("class") == "eunach" ||
		ob->query("class") == "bonze" ||
		ob->query("class") == "lama")
	{
		command("say 我平生最讨厌就是不三不四希奇古怪的人了！");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 我不收资质差的弟子，您请回吧！");
		return;
	}
	if ((int)ob->query_skill("bibo-shengong",1) < 50 )
	{
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧!");
		return;
	}
	if ((int)ob->query("shen") >100000 ||
		(int)ob->query ("shen") < -100000 )
	{
		command("say 我桃花岛与世隔绝，向来不与您这种成名人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if ( myfam["family_name"] == "桃花岛") return 1 ;
	if ((int)ob->query_temp("tmark/黄") == 1 )
		message_vision("黄药师看了看$N，说道：咱们现在是谁也不欠谁，\n你不要再找我学习技艺了。\n", ob);
	if (!(int)ob->query_temp("tmark/黄")) return 0; 
	ob->add_temp("tmark/黄", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jiuyin zhenjing1" )
	{
 		if (!(int)who->query_temp("tmark/黄"))
			who->set_temp("tmark/黄", 0);
		message_vision("黄药师看了看$N送来的秘籍，点了点头，说道：\n难得你将真经送回。你送的东西我就收下了。\n作为补偿,你可以从我这里学点功夫。\n",who);
		who->add_temp("tmark/黄", 120);
		return 1;
	}
	return 0;
}
string ask_me()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此话从何谈起？";
	if (query("book_count") < 1) return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/xuanfeng_book");
	ob->move(me);
	command("rumor "+me->query("name")+"拿到旋风扫叶腿法啦。\n");
	return "好吧，这本「旋风扫叶腿法」你拿回去好好钻研。";
}
string ask_yao()
{
	object ob, me = this_player();

	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此话从何谈起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你来晚了，无常丹刚巧给人了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/wuchangdan");
	ob->move(me);
	return "好吧，这丸无常丹就先给你吧。";
}
string ask_gua()
{
	object ob, me = this_player();
	
	if (me->query("family/master_id")!="huang yaoshi")
		return RANK_D->query_respect(me)+"非我弟子，不知此话从何谈起？";
	if (query("gua_count") < 1 || random(3) > 0)
		return "你来晚了，铁八卦刚巧给人了。";
	if (me->query_skill("count", 1) < 30 ||
		me->query_skill("bibo-shengong", 1) < 30)
		return "铁八卦你拿着也没什么用，还是留给别人了。";
	add("gua_count", -1);
	ob = new(__DIR__"obj/bagua");
	ob->move(me);
	return "好吧，这枚铁八卦就先给你吧。";
}
