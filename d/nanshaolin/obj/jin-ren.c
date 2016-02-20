// Obj: /d/nanshaolin/obj/jin-ren.c 金人
// Last Modified by winder on May. 29 2001

inherit NPC;

void create()
{
	set_name("金人", ({ "jin ren", "jin" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武金人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");
        set_weight(30000000);

	set("no_get", 1);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_qi", 300);
	set("eff_qi", 300);
	set("qi", 300);
	set("max_jing", 100);
	set("jing", 100);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 10);
	set("shen_type", 0);

	set("combat_exp", 1000000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}
int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status,prepare_status;
	string *sname, *mname,*pname;
	int i,temp;

	me = this_object();

	if (is_fighting()) return 0;

        if ( (int)ob->query("combat_exp") < 1000000)
                return notify_fail("你的功力不够，不能用金人练功！\n");

	if (random(me->query("fight_times")) >= 15)
		me->set("damaged", 1);

	if (me->query("damaged"))
		return notify_fail("这个金人已经被打坏了！\n");	

	if (me->query("last_fighter") == ob->query("id"))
		return 1;
	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 300 + random(300), me);	

	me->delete_skill("unarmed");
	me->map_skill("unarmed");
	me->map_skill("dodge");
	me->map_skill("parry");

	if ( !(skill_status = ob->query_skills()) ) return 1;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
	if ( !(map_status = ob->query_skill_map()) ) return 1;
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	}
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

		me->set("max_qi",    hp_status["max_qi"]*3);
		me->set("eff_qi",    hp_status["eff_qi"]*3);
		me->set("qi",        hp_status["qi"]*3);
		me->set("max_jing",  hp_status["max_jing"]*3);
		me->set("eff_jing",  hp_status["eff_jing"]*3);
		me->set("jing",      hp_status["jing"]*3);
		me->set("max_neili", hp_status["max_neili"]*2);
		me->set("neili",     hp_status["neili"]*2);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
