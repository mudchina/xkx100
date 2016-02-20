// wolfdog.c

inherit NPC;

void create()
{
	set_name("大狼狗", ({ "wolf dog", "dog" }) );
	set("race", "走兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的大狼狗。像是财主家里养的宠物。\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("combat_exp", 1000);
	
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
		"大狼狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"大狼狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	,		"大狼狗突然左嗅嗅右瞧瞧,大概又是在找包子吧:P\n"		
}) );
	set("accept_baozi",0);		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		(random(ob->query_kar() + ob->query_per()) < 30)
		 && !query("accept_baozi")) {
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
int accept_object(object who, object ob)
{
	if( ob->id("baozi") && !ob->is_character()) {
//?		destruct(ob);
		add("accept_baozi",1);
		command("halt");
		this_object()->remove_all_killer();
		this_object()->remove_all_enemy();
		if (query("accept_baozi")>2) {
		set_leader(who);
	  	message("vision", name() + "在你的脚边挨挨擦擦的，想讨东西吃。\n", environment());
		}
		else message("vision", name() + "用鼻子闻了闻包子，一口吞下,不再作声了。\n", environment());

	return 1;
	}
}

