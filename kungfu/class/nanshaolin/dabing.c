// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/dabing.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me_1(object);

void create()
{
	set_name("大病大师", ({ "dabing dashi", "dabing", "dashi"}));
	set("long", "他是一位身材矮小的老年僧人，面上皱纹堆垒。\n"
		"慈眉善目，露出悲天悯人之像。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("zhanzhuang-gong", 150);
	set_skill("dodge", 150);
	set_skill("yiwei-dujiang", 220);
// basic skill begin
	set_skill("shaolin-cuff", 220);
	set_skill("luohan-cuff", 220);
	set_skill("weituo-strike", 220);
	set_skill("sanhua-strike", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("nianhua-finger", 220);
	set_skill("boruo-strike", 220);
// basic skill end
// 掌和刀
	set_skill("strike", 150);
	set_skill("blade", 150);
	set_skill("cibei-blade", 220);
	set_skill("xiuluo-blade", 220);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("strike", "boruo-strike");
	map_skill("blade", "xiuluo-blade");
	map_skill("parry", "xiuluo-blade");

	prepare_skill("strike", "boruo-strike");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );
 	
	set("inquiry", ([
		"钢杵" : (: ask_me_1, "gangchu" :),
		"柴刀" : (: ask_me_1, "chaidao" :),
//		"挠钩" : (: ask_me_1, "naogou" :),
//		"套索" : (: ask_me_1, "taosuo" :),
	]));
	set("weapon_count", 10);
//	set("tools_count", 5);

	create_family("南少林派", 19, "心禅堂首座");
	setup();
	carry_object(WEAPON_DIR+"blade/jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if ( present(name, this_player()))
		return RANK_D->query_respect(this_player()) +"你现在身上不是有这样东西吗，怎麽又来要了？ 真是贪得无餍！";
	if (!(this_player()->query("pass_xin")))
		return "你是偷偷进来的吧，请出去吧！\n";
	if (query("weapon_count") < 1)
		return "抱歉，你来得不是时候，东西已经发完了。";
	ob = new("/d/nanshaolin/obj/" + name);
	ob->move(this_player());
	add("weapon_count", -1);
	message_vision("大病给$N一件"+ob->query("name")+"。\n",this_player());
	return "拿去吧。用此物为寺中服务。\n";
}

void attempt_apprentice(object ob)
{
	object me=this_object(); 
	mapping ob_fam, my_fam;
	string name, new_name;
	my_fam =me->query("family");
	name = ob->query("name");

	if(!(ob_fam=ob->query("family")) || ob_fam["family_name"]!="南少林派")
	{
		command("say "+RANK_D->query_respect(ob)+"与本派素无来往，不知此话从何谈起？");
		return;
	}
	if( !(ob->query("pass_xin")) )
	{
		command("say"+RANK_D->query_respect(ob) +"是怎么进来的？");
		return;
	}
	if( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"，贫僧哪里敢当！");
		return;
	}
	if( ob->query_skill("force", 1) < 60)
	{
		command("say "+RANK_D->query_respect(ob)+"，你的基本内功还需要磨练。贫僧到时再收你为徒。");
		return;
	}
	if( ob_fam["generation"]==(my_fam["generation"]+1) && name[0..1]=="元")
	{
		command("say "+ob_fam["master_name"]+"的徒弟怎么跑到我这儿来了，哈哈哈！");
		command("recruit "+ob->query("id"));
	}
	if( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		name = ob->query("name");
		new_name = "元" + name[2..3];
		command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");
		ob->set("name", new_name);
 		ob->set("title", "心禅堂职事僧");
		command("say 今后你的法名叫做"+new_name+"。\n");
		command("say 从今以后你就是心禅堂职事高僧了，望你好好深造！\n");
		command("recruit " + ob->query("id"));
	}
	else
		command("say "+RANK_D->query_respect(ob)+"，你是从哪蹦出来的，你不能越级拜师。");
	return;
}
