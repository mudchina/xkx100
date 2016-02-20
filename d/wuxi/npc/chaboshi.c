// chaboshi.c 茶博士

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("茶博士", ({ "cha boshi", "boshi", "cha" }));
	set("title", "茶馆跑堂");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("combat_exp", 800);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	say("茶博士笑眯眯地说道：这位" + RANK_D->query_respect(ob) + "，快请进来喝杯热茶，刚从山上运下的泉水沏的。\n");
}
