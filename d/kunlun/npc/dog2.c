// Npc: /d/kunlun/npc/dog2.c
// Last Modified by winder on Jun. 29 2001

inherit NPC;

void create()
{
	set_name("平寇将军", ({ "dog"}) );
	set("race", "走兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的大恶狗。\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 1000);
	
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30)
	{
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
	object ob;
	message_vision("$N惨嚎一声，死了！\n", this_object());
	ob = new(__DIR__"obj/goupi");
	ob->move(environment(this_object()));
	destruct(this_object());
}
