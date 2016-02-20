//menwei.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void greeting(object);
void init();
void create()
{
	set_name("门卫", ({ "men wei", "wei"}) );
	set("nickname", "铁狮子");
	set("gender", "男性" );
	set("age", 22);
	set("long", "这是个年富力强的卫兵，样子十分威严。\n");
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 300);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 9000+random(1000));
	set("score", 12000);

	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 30+random(10));
	set_skill("parry", 40);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor",20);

	setup();
	add_money("silver",20);
	carry_object("/d/baituo/obj/dadao")->wield();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if((string)ob->query("family/family_name")=="白驼山派")
	{
		say("门卫笑吟吟地说道：这位" + RANK_D->query_respect(ob) + "您辛苦了，快请进吧　。\n");
		return;
	}
	if(!ob->query("family/family_name"))
	{
		say("门卫满脸笑容地说道：这位" + RANK_D->query_respect(ob) + "您是来拜师的吧。\n师傅就在里面，快请进吧。\n");
		return;
	}
	if((int)ob->query("shen")>200)
	{
		say("门卫两眼一瞪，说道：这位" + RANK_D->query_respect(ob) + "你是来找麻烦的吧。\n我劝你不要轻举妄动！\n");
		return;
	}
}
