// little_bee.c

inherit NPC;

void create()
{
	set_name("小蜜蜂", ({ "little bee", "bee"}) );
	set("race", "昆虫");
	set("subrace", "飞虫");
	set("age", 2);
	set("long", "一只飞来飞去的小蜜蜂。\n");
	set("str", 30);
	set("dex", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	
	set("chat_chance", 2);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"小蜜蜂嗡嗡嗡飞过来，在你头上转了一圈，有飞走了。\n",
	}) );

	setup();
}

