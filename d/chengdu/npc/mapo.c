// mapo.c
// Last Modifyed by Winder on Dec. 24 2001

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("陈麻婆", ({ "chen mapo", "chen" }));
	set("title", "麻婆豆腐创始人");
	set("nickname",HIW "豆腐西施" NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	set("long",
		"陈麻婆可是成都城出名的人物，虽然年过三十，依然风韵犹存。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("inquiry", ([
		"麻婆豆腐" : "这是我们成都的特产，安逸得很哦。\n",
	]));
	set("vendor_goods", ({
		__DIR__"obj/doufu",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
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
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) {
	case 0 :
		say("陈麻婆笑咪咪地说道：这位" + RANK_D->query_respect(ob) +
			"，快请进。\n");
		break;
	case 1 :
		say("陈麻婆说道：哟！这位" + RANK_D->query_respect(ob) + 
			"您来了啊！本店的麻婆豆腐硬是安逸得很！\n");
		break;
	}
}


