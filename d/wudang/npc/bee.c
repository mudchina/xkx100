//bee.c

inherit NPC;

void create()
{
	set_name("蜜蜂", ({"bee"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 8);
	set("long", "这是一只蜜蜂，正忙着采蜜。\n");
	
	set("str", 40);
	set("dex", 50);
	set_temp("apply/attack", 33);
	set_temp("apply/armor", 20);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"蜜蜂嗡嗡嗡飞过来，在你头上转了一圈，有飞走了。\n",
	}) );

	setup();
}

