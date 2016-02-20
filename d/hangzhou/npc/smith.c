// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("铁匠", ({ "tiejiang", "smith" }));
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "铁匠正用铁钳夹住一块红热的铁块放进炉中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/d/city/obj/changjian",
		"/d/city/obj/hammer",
		"/d/beijing/obj/tudao",
		"/d/xingxiu/obj/tiegun",
		"/d/city/obj/gangdao",
	}));
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}
void init()
{
	object ob,me;

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
	say("铁匠说道：欢迎这位"+RANK_D->query_respect(ob)+"光临，请随便参观。\n");
}
