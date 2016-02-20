// sun.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("孙二娘", ({ "sun erniang", "sun", "waiter" }) );
	set("gender", "女性" );
	set("age", 22);
	set("long",
		"这位老板娘正笑咪咪地坐在柜台后面，向着门外张望。\n");
	set("combat_exp", 100000);
	set("attitude", "friendly");
	set("rank_info/respect", "母夜叉");
	set_skill("dodge", 80);
	set_skill("unarmed",80);
	set_skill("parry", 80);
	set_skill("literate", 150);

	set("vendor_goods", ({
		__DIR__"obj/jitui",
		__DIR__"obj/baozi",
		__DIR__"obj/flagon",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) )
	{
		case 0:
			say("孙二娘笑咪咪地说道：这位"+RANK_D->query_respect(ob) + "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say("孙二娘用脖子上的毛巾抹了抹手，说道：这位" +RANK_D->query_respect(ob)+"，请进请进。\n");
			break;
	}
}

