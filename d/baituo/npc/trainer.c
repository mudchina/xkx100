// trainer.c
// Last Modified by Winder on May. 15 2001

inherit NPC;
void greeting(object);
void init();
void create()
{
	set_name("教练", ({ "trainer"}) );
	set("gender", "男性" );
	set("age", 25);
	set("long", "这是个和蔼可亲的教练。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 30000);
	set("score", 20000);

	set_skill("force", 60);
	set_skill("dodge", 70);
	set_skill("unarmed", 70);
	set_skill("parry", 60);
	set_skill("staff",60);

	create_family("白驼山派", 3, "弟子");
	setup();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "白驼山派")
	{
		if(ob->query("qi")<60)
			message_vision("教练对着$N笑道：练功累吧？没关系，苦尽甜来嘛。\n",ob);
		else
			message_vision("教练对着$N夸道：你又来练功，精神可嘉！\n",ob);
	}
}

void attempt_apprentice(object ob)
{
	command("say 我不能收徒。你还是拜李教头吧。\n");
	return;
}

int accept_fight(object ob)
{
	if ((string)ob->query("family/family_name") == "白驼山派")
	{
		if((int)ob->query("combat_exp")<10000)
			return notify_fail("教练笑道：你的经验太低了，还是找陪练童子比划吧！(bi tongzi)\n");
	}
	return 1;
}
