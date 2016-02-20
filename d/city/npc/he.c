// he.c

inherit NPC;

void create()
{
	set_name("何员外", ({ "he yuanwai", "he" }));
	set("shen_type", -1);

	set("gender", "男性" );
	set("age", 53);
	set("long", "何员外是扬州城里的首富，和当地的官绅都有很深的交情。\n");
	set("combat_exp", 400);
	set("attitude", "friendly");
	setup();

	carry_object(__DIR__"obj/choucloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("何员外奇怪地对你说道：“你这人怎么随随便便地就跑到我的园子里来？”\n");
}
