//hudie.c

inherit NPC;

void create()
{
	set_name("蝴蝶", ({"hudie"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 8);
	set("long", "这是一只在花间翩翩飞舞的蝴蝶，似乎不怕人呢。\n");

	set("str", 20);
	set("dex", 50);
	set_temp("apply/attack", 33);
	set_temp("apply/armor", 20);

	set("chat_chance", 5);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"蝴蝶飞过来，绕着你的身体飞舞起来。等你伸出手来想抓住它时，它又飞走了。\n",
	 }) );

	setup();
}

