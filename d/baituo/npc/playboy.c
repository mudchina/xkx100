// playboy.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("花花公子", ({ "playboy" }) );
	set("nickname", "采花大盗");
	set("gender", "男性" );
	set("age", 19);
	set("long", "这是个流里流气的花花公子。\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("max_qi", 400);
	set("max_jing", 200);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	setup();
	add_money("silver", 10);
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
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")=="女性")
	{
		if(random(2)==1)
			say(" 花花公子色迷迷说："+RANK_D->query_respect(ob)+ "干嘛那么着急赶路，陪我玩玩不行吗？\n");
		else
			say(" 花花公子唱道：路边的野花不采白不采~~。这位"+RANK_D->query_respect(ob)+ "你说是吗？\n");
	}
}
