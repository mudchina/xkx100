// xiaoer2.c 酒店小二

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		LIQUID_DIR+"jiudai",
		LIQUID_DIR+"wineskin",
		TEA_DIR+"fuchun",
		TEA_DIR+"longjing",
		TEA_DIR+"kuijian",
		FOOD_DIR+"kaoya",
		FOOD_DIR+"jitui",
		FOOD_DIR+"baozi",
		FOOD_DIR+"mian",
		FOOD_DIR+"tofu",
		FOOD_DIR+"gancai",
		FOOD_DIR+"jiaozi",
		FOOD_DIR+"jicai",
		FOOD_DIR+"jiudai",
		FOOD_DIR+"nuomi",
		FOOD_DIR+"sanding",
		FOOD_DIR+"shaomai",
		FOOD_DIR+"shengrou",
		FOOD_DIR+"shuijing",
		FOOD_DIR+"sunrou",
		FOOD_DIR+"xiaocai",
		FOOD_DIR+"xiehuang",
		FOOD_DIR+"xisha",
		FOOD_DIR+"yacai",
		FOOD_DIR+"yougao",
		FOOD_DIR+"zhima",
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
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
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

	ob->move("/d/city/ganquanjie");
	message("vision","只听“乒”地一声，" + ob->query("name") + "被人从醉仙楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
