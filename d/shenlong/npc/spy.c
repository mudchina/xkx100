// /d/shenlong/npc/spy.c
// Last Modified by winder on Jul. 12 2002

inherit NPC;
inherit F_MASTER;
//inherit F_CLEAN_UP;

void auto_enable();
int is_sg_spy() { return 1;}

void create()
{
	set_name("魏无双", ({ "wulin mengzhu", "mengzhu", "zhu" }) );
	set("title", "武林盟主" );
	set("gender", "男性" );
	set("age", 40);
	set("long","他就是雄踞武林，号召天下，威风赫赫的当今武林盟主。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 500);
	set("eff_qi", 500);
	set("qi", 500);
	set("max_jing", 300);
	set("jing", 300);
	set("neili", 500);

	set("max_neili", 500);
	set("jiali", 40);

	set("shen_type", -1);

	set_skill("force",  100); 
	set_skill("unarmed",100);
	set_skill("sword",  100);
	set_skill("dodge",  100);
	set_skill("parry",  100);

	set("weapon", WEAPON_DIR"sword/changjian");
	set("armor", CLOTH_DIR"cloth");

	setup();

	carry_object(WEAPON_DIR"sword/changjian")->wield();
	carry_object(CLOTH_DIR"cloth")->wear(); 
}

void init()
{
	::init();

	auto_enable();

	if( !this_player()->query("yijin_wan") && interactive(this_player()) &&
		 !is_killing() )
		 call_out("do_kill", 1, this_player());
}

void do_kill(object ob)
{
	kill_ob(ob);
	ob->fight_ob(this_object());
}

void auto_enable()
{
	object me = this_object();
	string *sorted_skills, *mapped_types = ({});
	string temp, pre1, pre2;
	mapping skill_status;
	int i, j;
	string *unarmed_types = ({
		"finger",
		"hand",
		"cuff",
		"claw",
		"strike",
		"leg",
	});
	string *weapon_types = ({
		"sword",
		"blade",
		"stick",
		"staff",
		"club" ,
		"hook",
		"throwing",
		"force",
		"parry",
		"dodge",
		"whip",
		"hammer",
	});

	skill_status = me->query_skills();
	sorted_skills = keys(skill_status) - unarmed_types - weapon_types;

	for (i=1; i<sizeof(sorted_skills); i++)
	{
		j = i;
		temp = sorted_skills[j];
		while( j>0 &&
		       skill_status[temp] > skill_status[sorted_skills[j-1]] ) {
			sorted_skills[j] = sorted_skills[j-1];
			j--;
		}
		sorted_skills[j] = temp;
	}

	for (i=0; i<sizeof(unarmed_types); i++)
		me->prepare_skill(unarmed_types[i]);

	for (i=0; i< sizeof(sorted_skills); i++)
	{
		for (j=0; j<sizeof(weapon_types); j++) 
			if (SKILL_D(sorted_skills[i])->
				valid_enable(weapon_types[j]))
			{
				me->map_skill(weapon_types[j],sorted_skills[i]);
				mapped_types += ({weapon_types[j]});
			}
		weapon_types -= mapped_types;
		for (j=0; j<sizeof(unarmed_types); j++) 
			if (SKILL_D(sorted_skills[i])->
				valid_enable(unarmed_types[j]))
			{
				me->map_skill(unarmed_types[j], sorted_skills[i]);
				mapped_types += ({unarmed_types[j]});
				if(sizeof(me->query_skill_prepare())==0)
				{
					pre1 = sorted_skills[i];
					me->prepare_skill(unarmed_types[j], pre1);
				}
				else
					if(sizeof(me->query_skill_prepare())==1 && SKILL_D(pre1)->valid_combine(sorted_skills[i]))
					{
						pre2 = sorted_skills[i];
						me->prepare_skill(unarmed_types[j], pre2);
					}
			}
			unarmed_types -= mapped_types;
	}
	me->set("jiali", me->query_skill("force")/2);
	me->reset_action();

}

// well, some unresolved mysterious bug, so abandon the following way:)
// overload kill_ob in /feature/attack.c added by xuy.
/*void kill_ob(object ob)
{
	auto_enable();

	::kill_ob(ob);
}*/

//overload fight_ob
/*void fight_ob(object ob)
{
	auto_enable();

	::fight_ob(ob);
}*/
