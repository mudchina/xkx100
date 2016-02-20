// ox.c
// Last Modified by winder on Sep. 12 2001

inherit NPC;

void create()
{
	set_name("牦牛", ({ "mao niu","niu" }) );
	set("race", "走畜");
	set("age", 12);
	set("long", "一头发怒的公牛，两个角上微微闪着金光。\n");

	set("str", 25);
	set("cor", 24);
	set("combat_exp",15000);

	set_temp("apply/attack", 15);
	set_temp("apply/armor", 25);
   
	set("chat_chance",5);
	set("chat_msg",({
		"牦牛瞪着碗大的眼睛，仔细研究着你。\n",
		"牦牛张嘴对天叫了两声，你却没听到一点声音。\n",
	}));
	setup();
}

void die()
{
	message_vision("$N怒哼一声，一头撞向山壁，不见了。\n",this_object());
	new(__DIR__"obj/niujiao")->move(environment(this_object()));
	destruct(this_object());
	return;
}
