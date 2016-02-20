// tianlang.c 天狼子
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();

void create()
{
	set_name("天狼子", ({ "tianlang zi", "tianlang", "zi" }));
	set("nickname", "星宿派三弟子");
	set("long", "一个貌似忠厚，其实十分狡狯的胖子。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 27);
	set("int", 16);
	set("con", 25);
	set("dex", 27);
	
	set("max_qi", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 15);
	set("combat_exp", 150000);
	set("score", 30000);
	set("di_count", 10);

	set_skill("force", 70);
//	set_skill("huagong-dafa", 4);
	set_skill("dodge", 50);
	set_skill("zhaixinggong", 40);
	set_skill("strike", 50);
	set_skill("chousui-zhang", 30);
	set_skill("claw", 50);
	set_skill("sanyin-wugongzhao", 30);
	set_skill("parry", 40);
	set_skill("poison", 40);
	set_skill("staff", 70);
  	set_skill("tianshan-zhang", 70);
//	set_skill("literate", 50);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
  	map_skill("parry", "tianshan-zhang");
  	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");

	set("env/wimpy", 60);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("星宿派", 2, "弟子");
	set("inquiry", ([
		"星宿派" : "你想加入，就拜我为师。",
		"星宿海" : "去星宿海干什么？拜我为师就够你学的了。",
		"丁春秋" : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
		"老仙"   : (: ask_job :),
		"job"    : (: ask_job :),
	]));
	create_family("星宿派", 2, "弟子");

	setup();
  	carry_object("/clone/weapon/gangzhang")->wield();
  	carry_object("/d/xingxiu/obj/changpao")->wear();
}
void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派")
	{
		say("天狼子对"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 70 || ob->query("shen") > -5000)
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
 
	if(!fam) return "看得出你对老仙态度恭敬，何不先加入我星宿派呢？";
	if (fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
		return "你对老仙的态度看上去不太恭敬啊！";
	if(exp<100000) return "哈哈哈，你再加把力练功吧。";
	if(exp>=250000)
		return "老仙最近的情况我不太清楚，你去问问我师兄狮吼子吧。";
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
	ob->set("name", YEL "黄玉短笛" NOR);
	ob->set("long", YEL"这玉笛短得出奇，只不来七寸来长、通体金黄，晶莹可爱。\n" NOR);
	ob->set("xx_user", getuid(me));
	if(fam["family_name"] != "星宿派")
	me->set_temp("apply/short", ({YEL"星宿派随从 "NOR+me->name()+"("+me->query("id")+")"}));               
	me->set_temp("xx_job", 1);
	message_vision("\n$N拿出一只玉制短笛，交给$n。\n", this_object(), me);
	return "老仙最近心情不佳，你可要多多为他老人家分忧才是！\n";    
}

