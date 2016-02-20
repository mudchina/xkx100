// woman.c

inherit NPC;

void create()
{
	set_name("少妇",({ "woman" }) );
	set("gender", "女性" );
	set("age", 25);
	set("long", "这是个美丽少妇，双目含情，一对胸脯鼓鼓囊囊。\n");
	set_temp("apply/defense", 6);
	set("combat_exp", 700);
	set("shen", 100);
	set("shen_type", 1);
	set("str", 14);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
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
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) )
	{
		case 0:
			say("少妇低声说道：这位" + RANK_D->query_respect(ob) + "，瞧我这顽皮小儿，奴家该怎么办啊？\n");
			break;
		case 1:
			say("少妇呜咽着说道：这位" + RANK_D->query_respect(ob) + "，奴家的那个死鬼不知道又到哪里鬼混去了，您帮我管教一下小儿吧。\n");
			break;
	}
}
