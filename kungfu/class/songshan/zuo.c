// zuo.c

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>

string ask_book();
string ask_book1();
void create()
{
	set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
	set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 2400);
	set("max_neili", 2400);
	set("jiali", 30);
	set("max_qi",2000);
	set("max_jing",1200);
	set("combat_exp", 3000000);
	set("shen", -200000);
	set("book_count", 1);
	set("book_count1", 1);

	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("songshan-sword", 300);
	set_skill("songyang-strike", 300);
	set_skill("poyun-hand", 300);
	set_skill("hanbing-zhenqi", 200);
	set_skill("fuguanglueying", 300);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	set("inquiry",([
		"秘籍"	     : (: ask_book :),
		"掌谱"	     : (: ask_book :),
		"大嵩阳掌谱" : (: ask_book :),
		"剑谱"	     : (: ask_book1 :),
		"嵩山剑谱"   : (: ask_book1 :),
	]));

	create_family("嵩山派", 13, "掌门");
	setup();

	carry_object(WEAPON_DIR+"kuojian")->wield();
	carry_object(__DIR__"obj/yellow-cloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	command("say 我派为五岳盟主！入我门来，定须光大我嵩山一派。");
	command("recruit " + ob->query("id"));
}

string ask_book()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		"与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count") < 1) return "你来晚了，本派的秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/songyang-zhangpu");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到大嵩阳掌谱啦。\n");
	return "好吧，这本「大嵩阳掌谱」你拿回去好好钻研。";
}

string ask_book1()
{
	object ob;
	
	if (this_player()->query("family/family_name")!="嵩山派")
		return RANK_D->query_respect(this_player()) +
		"与本派毫无瓜葛，我派的武功典籍可不能交给你。";
	if (query("book_count1") < 1) return "你来晚了，本派的秘籍不在此处。";
	add("book_count1", -1);
	ob = new("/clone/book/sword_book4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到嵩山剑谱啦。\n");
	return "好吧，这本「嵩山剑谱」你拿回去好好钻研。";
}
