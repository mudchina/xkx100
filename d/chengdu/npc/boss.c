// Room: /d/chengdu/npc/boss.c
// Last Modifyed by Winder on Jan. 4 2002

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("老板娘", ({ "lao ban", "lao", "ban" }));
	set("nickname", "笑咪咪");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 36);
	set("long","她成天带着笑容，可是心头却灵醒得很。\n作为茶馆的老板娘，成天和一帮没事干的无聊家伙混在一起。油得很。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("vendor_goods", ({
		FOOD_DIR"peanut",
		FOOD_DIR"tofu",
		__DIR__"obj/longhucui",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("老板娘笑眯眯地说道：这位" + RANK_D->query_respect(ob) + "，快请进来喝杯热茶。\n");
		break;
	case 1 :
		say("老板娘说道：哟！这位" + RANK_D->query_respect(ob) + "您来了啊！本店有刚炸好的五香花生出售。\n");
		break;
	}
}

