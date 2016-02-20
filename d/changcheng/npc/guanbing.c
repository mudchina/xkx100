// guanbing.c 官兵

inherit NPC;

void create()
{
	set_name("官兵", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "这就是守卫边疆的官兵，虽然他们年纪不大，由于长年的风吹日晒，使他们显得很苍老。\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

//	if (random(2) == 1) {
//		set("chat_chance", 10);
//		set("chat_msg", ({
//			(: random_move :),
//		}));
//	}

        set("chat_chance", 10);
	set("chat_msg", ({
		"官兵大声喝道：大胆，竟敢造反不成？\n",
		"官兵叹了口气：唉，很久没有回家了，不知道她怎么样了？\n",
		"官兵大声说道：只要有我在这里就没有人能打过去！\n",
	}));
	setup();
	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/d/city/obj/junfu")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
