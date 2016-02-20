// Last Modified by Sir on May. 22 2001
// yi.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include <command.h>
#include "hengshan.h";
string ask_for_join();
string ask_me();
void create()
{
	set_name("定逸师太", ({ "dingyi shitai", "shitai", "dingyi" }) );
	set("long", 
	"她是恒山派的定逸师太，性格刚猛，为人正直，有巾帼不让须眉之风。\n"
	"她眼中精光四射，绝无半点老态。\n");
	set("gender", "女性");
	set("class", "bonze");
	set("age", 45);
	set("attitude", "peaceful");
	set("per", 24);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"join"  : (: ask_for_join :),
		"秘籍"  : (: ask_me :),
		"手法精要" : (: ask_me :),
		"还俗"  : "恒山弟子，不能还俗。",
	]));
	set("env/wimpy", 60);	

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.yuyin" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: perform_action, "sword.liuyun" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield chacngjian") :),
		(: command("wield changjian") :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "hand.break" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
		(: perform_action, "strike.diezhang" :),
	}));

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 1500000);
	set("score", 1000);
	set("book_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 180);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 180);
	set_skill("hand", 150);
	set_skill("buddhism", 150);
	set_skill("baiyun-xinfa",180);	
	set_skill("hengshan-jian", 250);
	set_skill("chuanyun-shou",250);
	set_skill("tianchang-zhang",250); 
	set_skill("lingxu-bu", 250);
	set_skill("literate", 100);

	map_skill("force","baiyun-xinfa");
	map_skill("sword", "hengshan-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "hengshan-jian");
	map_skill("dodge", "lingxu-bu");

	create_family("恒山派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	string name, new_name;

	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫尼不收俗家弟子。");
		return;
	}
	
	if ((int)ob->query_skill("baiyun-xinfa",1) < 90 )
	{
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000) 
	{
		command( "say 你若能多为侠义之举，当能承我衣钵。\n");
		return;
	}

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能努力行善，济度众生，以光大我恒山派。");
	command("recruit " + ob->query("id"));
	name = ob->query("name");
	new_name = "仪" + name[2..3];
	command("say 从今以后你的法名叫做" + new_name + "。");	
	ob->set("name", new_name);
}

string ask_me()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="恒山派")
		return RANK_D->query_respect(this_player()) +
		"与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count") < 1)
		return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/basic_hand_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到手法精要啦。\n");
	return "好吧，这本「手法精要」你拿回去好好钻研。";
}
