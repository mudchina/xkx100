// goudu.c 苟读
// Modified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string ask_me();

void create()
{
	set_name("苟读", ({ "gou du", "gou" }));
	set("nickname","“函谷八友”书呆");
	set("long","他看上去也是几十岁的人了，性好读书，诸子百家，无所不窥，是一位极有学问的宿儒，却是纯然一个书呆子的模样。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

	set("inquiry", ([
		"论语":(:ask_me:),
	]) );

	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("combat_exp", 360000);
	set("score", 40000);

	set_skill("literate", 100);
	set_skill("blade", 80);
	set_skill("ruyi-dao", 120);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("hand", 80);
	set_skill("parry", 80);
	set_skill("lingboweibu", 120);
	set_skill("beiming-shengong",80);
	set_skill("zhemei-shou", 120);
	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("blade", "ruyi-dao");
	map_skill("parry", "ruyi-dao");
	prepare_skill("hand", "zhemei-shou");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "dodge.lingbo" :),
		(: perform_action, "strike.zhong" :),
		(: perform_action, "hand.duo" :),		
		(: exert_function, "shield" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/food/jiudai");
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	object me,ob;
	ob=this_player(); 

	if (query("book_count") < 1)
		return "你来晚了，那本《论语》我已经赠送给别人了。";   
	add("book_count", -1);                  

	if(ob->query("family/master_id")=="xiaoyao zi")
	{
		command("say 师叔想要《论语》，拿去就是。");
		message_vision(HIY"苟读从怀里掏出一本旧书，交了给$N \n\n"NOR,ob);
		me=new("/clone/book/lbook5");
		me->move(ob);
		return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
	}
	command("say 哈哈，《论语》就没有了，这里有我派高手从少林盗来的书。");
	command("say 既然你那么好学，我就把它送给你吧。\n");
	message_vision(HIY"苟读翻箱倒柜找了半天，找出一本旧书，交了给$N \n\n"NOR,ob);
	if (random(2) == 1) me=new("/clone/book/strike_book");
	else me=new("/clone/book/book-paper");
	me->move(ob);

	return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
}
