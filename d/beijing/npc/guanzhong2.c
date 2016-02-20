// guanzho2.c
inherit NPC;

void create()
{
	set_name("观众乙", ({ "yi"}) );
	set("gender", "男性");
	set("age", 30);
	set("long",
		"这家伙满脸横肉，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 10000);
        set("shen_type", -1);
	set("attitude", "friendly");

	set("apply/attack", 20);
	set("apply/defense", 20);


	set_skill("unarmed", 40);
	set_skill("sword", 20);
	set_skill("parry", 40);
	set_skill("dodge", 40);
	setup();

	carry_object(CLOTH_DIR"cloth")->wear();
        carry_object("/d/city/obj/duanjian")->wield();
	add_money("silver", 1);
}

void init()
{

	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight"))
	{
		if( !ob->query_temp("warned") ) {
			command("say 他妈的，今天老子心情不好，小心我宰了你！");
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，受死吧！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
