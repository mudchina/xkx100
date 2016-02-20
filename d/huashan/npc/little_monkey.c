// little_monkey.c

inherit NPC;

void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "走兽");
	set("age", 2);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n"
	    "陆大有整天调教得它无比伶俐，现在正骑在陆大有的脖子上。\n");
	set("shen", 0);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
        set("attitude", "peaceful");

	set("no_get", "1");
	set("max_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set("fight_times", 0);	

	set("chat_chance", 15);
	set("chat_msg", ({
		"小猴伸出小抓挠挠头，冲你扮个鬼脸。\n",
		"小猴懒洋洋地打了个哈欠，爬到陆大有头顶，又翻身下到主人肩头。\n",
		"小猴伸抓捉住了身上的虱子，看了两眼，使劲就是一捏! \n",
	}));
	setup();
        
}
/*
int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("这个小猴已经被打伤了！\n");	

	if (random(me->query("fight_times")) >= 5) {
		me->set("damaged", 1);
		return notify_fail("这个小猴已经被打怕了！\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("这个小猴已经不想和你玩了！\n");	

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 1000 + random(300), me);	

// delete and copy skills //

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	
// delete and copy skill maps //

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	
// delete and copy skill prepares //

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
*/
