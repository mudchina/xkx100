//Edited by fandog, 02/15/2000

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("伙计", ({ "huo ji", "huo", "waiter" }) );
	set("gender", "男性" );
	set("age", 17);
	set("long",
		"这位小伙计正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小伙计");
	set("no_get", "1");
	set("vendor_goods", ({
		"/d/jiangling/obj/donggua",
		"/d/jiangling/obj/houtou",
		"/d/jiangling/obj/longfeng",
		"/d/jiangling/obj/tianma",
		"/d/jiangling/obj/wuchangyu",
		"/d/jiangling/obj/xianggu",
		"/d/jiangling/obj/zzjiayu",
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
			say("小伙计笑咪咪地说道：这位" + RANK_D->query_respect(ob) + "，您请喝杯茶，歇歇脚唦。\n");
			break;
		case 1:
			say("小伙计用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob) + "，您有什么事？\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/jiangling/hzjie1");
	message("vision", "只听“乒”地一声，" + ob->query("name") + "被人从四季美里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
