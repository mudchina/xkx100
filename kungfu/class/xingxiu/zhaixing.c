// zhaixing.c 摘星子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_book();
string ask_job();

void create()
{
	set_name("摘星子", ({ "zhaixing zi", "zhaixing", "zi" }));
	set("nickname", "星宿派大师兄");
	set("long", 
		"一个二十七八岁的白衣年轻人。他身材高瘦，脸色青
中泛黄，面目却颇英俊。眼光中透出一丝乖戾之气。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("class", "fighter");
	set("str", 26);
	set("int", 28);
	set("con", 26);
	set("dex", 26);
	
	set("max_qi", 700);
	set("max_jing", 700);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 300000);
	set("score", 40000);
	set("di_count", 10);

	set_skill("force", 70);
	set_skill("huagong-dafa", 50);
	set_skill("throwing", 70);
	set_skill("feixing-shu", 80);
	set_skill("dodge", 70);
	set_skill("zhaixinggong", 100);
	set_skill("strike", 80);
	set_skill("chousui-zhang", 80);
	set_skill("claw", 80);
	set_skill("sanyin-wugongzhao", 80);
	set_skill("parry", 70);
	set_skill("poison", 70);
	set_skill("staff", 70);
//	set_skill("tianshan-zhang", 60);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("throwing", "feixing-shu");
//	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("inquiry", ([
		"星宿派"    : "你想加入，就拜我为师。",
		"星宿海"    : "去星宿海干什么？拜我为师就够你学的了。",
		"丁春秋"    : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
		"老仙"      : (: ask_job :),
		"job"       : (: ask_job :),
		"炼心弹"    : (: ask_me :),
		"秘籍"      : (: ask_book :),
		"天山器法"  : (: ask_book :),
	]));
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
	}));
	set("dan_count", 1);
	set("book_count", 1);

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/lianzi")->wield();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (query("dan_count") < 1)
		return "你来晚了，没有练心弹了。";
	add("dan_count", -1);
	ob = new("/d/xingxiu/obj/lianxindan");
	ob->move(this_player());
	return "这些练心弹够你用的了吧。";
}

string ask_book()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，现在没什么剩的了。";
	add("book_count", -1);
	ob = new("/clone/book/throw_book");
	ob->move(this_player());
	return "好吧，这本书你拿回去好好看看吧。";
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派")
	{
		say("摘星子对"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1)<90 || ob->query("shen") > -50000)
	{
		command("say 你的条件还不够，我才不想收你呢。");
		return;
	}
	command("say 好吧，看来你的化功大法有点基础了，我就收下你吧。");
	command("recruit " + ob->query("id"));
}
string ask_job()
{
	object me, ob;
	mapping fam;
	int shen, exp;
	me = this_player();
	fam = (mapping)me->query("family");
	shen = me->query("shen");
	exp=me->query("combat_exp",1); 
 
	if(!fam) return "看得出你对老仙态度恭敬，何不加入我星宿派呢？";
	if(fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "你对老仙的态度看上去不太恭敬啊！";
	if(exp<500000)
		return "哈哈哈，你再加把力练功吧。";
	if(exp>=750000)
		return "老仙最近的情况我不太清楚，你自己去问问他老人家吧。";
	if(me->query_condition("wait_xx_task"))
		return "上次搞砸了，这次你就等等吧。";
	if(interactive(me) && me->query_temp("xx_job"))
		return "你怎么还在这里发呆？";
	if(interactive(me) && me->query_condition("wait_xx_task"))
		return "老仙现在心情还好，不用你来为他分忧。";
	if(query("di_count") < 1)  
		return "老仙现在心情还好，你别再来烦我了。";
	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", MAG "紫玉短笛" NOR);
	ob->set("long", MAG"这玉笛短得出奇，只不来七寸来长、通体紫红，晶莹可爱。\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "星宿派")
		me->set_temp("apply/short", ({MAG"星宿派门客 "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N拿出一只玉制短笛，交给$n。\n", this_object(), me);
	return "老仙最近心情不佳，你可要多多为他老人家分忧才是！\n";    
}
