// fengqi.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("凤七", ({ "feng qi", "feng", "qi" }) );
	set("gender", "男性" );
	set("title", "酒楼老板" );
	set("age", 42);
	set("long",
"凤七是凤天南的远房祖弟，在这英雄楼当掌柜。武功没有什么，为人却极是机灵。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "七哥");
	set("vendor_goods", ({
		"/clone/food/jitui",
		"/clone/food/jiudai",
		"/clone/food/baozi",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family")) 
		&& myfam["family_name"] == "丐帮" 
		&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "凤七笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "凤七笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，快请进。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n凤七大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/foshan/street4");
	message("vision", "只听“乒”地一声，" + ob->query("name") + "被人从英雄楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
