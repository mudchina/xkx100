// Last Modified by winder on Apr. 25 2001
// robber3 for dart
#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
	set_name("蒙古高手",({"menggu gaoshou","gaoshou"}));
	set("long","这是一位侵犯中原的蒙古武功高手。\n");
	set("gender", "男性" );
	set("age", random(30)+14);
	
	set("vendetta/authority", 1);
	set("attitude", "peaceful");	
	set("bellicosity", 100000);
	set("max_qi", 2000);
	set("eff_qi", 2000);
	set("qi", 2000);
	set("max_jing", 1200);
	set("jing", 1200);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("shen_type", -10);
	set("combat_exp", 600000);
	set("no_get",1);
	set("quest_no_guard",1);

	set_skill("force", 180);
	set_skill("unarmed", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("get wan dao") :),
                (: command("wield wan dao") :),
                (: perform_action, "blade.shendao" :),		
		(: perform_action, "strike.leiting" :),				
		(: exert_function, "fanchang" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),		
	}) );		

	setup();
	carry_object(__DIR__"wandao")->wield();
	carry_object("/d/city/obj/tiejia")->wear();
}

void do_change(object ob)
{
	object me;
	mapping hp_status, skill_status;
	string *sname;
	int i, temp;
	me = this_object();

	if ( mapp(skill_status = me->query_skills()) )
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);
		temp = sizeof(skill_status);
		for(i=0; i<temp; i++)
		{
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) )
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);
		temp = skill_status[0];
		for(i=0; i<sizeof(skill_status); i++)
		{
			if(sname[i]=="force")i++;
			if (skill_status[sname[i]] >= temp)
			{
				temp = skill_status[sname[i]];
			}
		}
	}

        me->set_skill("xue-dao", temp-random(10));
	me->set_skill("strike",temp-random(10));
	me->set_skill("xianglong-zhang",temp-random(10));
	me->set_skill("dodge", temp-random(10));
	me->set_skill("blade", temp-random(10));
	me->set_skill("parry", temp-random(10));
	me->set_skill("shenkong-xing", temp-random(10));
	me->set_skill("longxiang", temp-random(10));
	me->set_skill("huntian-qigong", temp-random(10));

	me->map_skill("force", "longxiang");
	me->map_skill("dodge", "shenkong-xing");
	me->map_skill("parry", "xue-dao");
	me->map_skill("blade", "xue-dao");
	me->map_skill("strike","xianglong-zhang");
	me->set_temp("apply/damage", 150);
	if (random(20)>15)
	{
		me->set_temp("apply/attack", 200);
		me->set_temp("apply/defense", 200);
		me->set_temp("apply/armor", 200);
		me->set_temp("apply/damage", 200);
	}
	me->map_skill("strike","xianglong-zhang");
	prepare_skill("strike", "xianglong-zhang");	


/* copy hp */

	hp_status = ob->query_entire_dbase();
	me->set("str", hp_status["str"]+random(2));
	me->set("int", hp_status["int"]);
	me->set("con", hp_status["con"]+random(2));
	me->set("dex", hp_status["dex"]+random(10));
	me->set("combat_exp",hp_status["combat_exp"]*5/4);
	me->set("ygjg",ob);
	me->set("max_qi", hp_status["max_qi"]*3/4);
	me->set("eff_qi", hp_status["max_qi"]*3/4);
	me->set("qi", hp_status["max_qi"]*3/4);
//	me->set("max_jing", hp_status["max_jing"]*3/4);
//	me->set("eff_jing", hp_status["eff_jing"]*3/4);
//	me->set("jing",	hp_status["eff_jing"]*3/4);
	me->set("max_neili", hp_status["max_neili"]*3/4);
	me->set("neili", hp_status["max_neili"]*3/4);
  if (hp_status["neili"] >=  hp_status["max_neili"]*2)
	me->set("neili", hp_status["neili"]*5);
}

void die()
{
	object ob;
	object robber;
	object room;
	ob=query_temp("last_damage_from");
	room = environment(ob);	
	ob->start_busy(1);

	if(ob->query_temp("guosc_mis_num")>=0)
	{
		ob->add_temp("guosc_mis_num",1);
	}
       if ((int)ob->query_condition("guosc_mis")>=1&& ob->query_temp("guosc_mis_where")==room->query("short"))
       {  
          switch( random(5) )
	{
		case 0:
			message_vision(HIR"城下又爬上来一个蒙古兵士。\n"NOR,ob);
			robber=new(__DIR__"robber1");
                        robber->set("owner",ob->query("id"));
			robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 1:
			message_vision(HIR"城下又爬上来一个蒙古将领。\n"NOR,ob);
			robber=new(__DIR__"robber2");
                        robber->set("owner",ob->query("id"));
			robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 2:
			message_vision(HIR"城下又爬上来一个蒙古高手。\n"NOR,ob);
			robber=new(__DIR__"robber3");
                        robber->set("owner",ob->query("id"));
			robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 3:
			message_vision(HIR"城下又爬上来一个蒙古兵士。\n"NOR,ob);
			robber=new(__DIR__"robber1");
                        robber->set("owner",ob->query("id"));
			robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
		case 4:
			message_vision(HIR"城下又爬上来一个蒙古将领。\n"NOR,ob);
			robber=new(__DIR__"robber2");
                        robber->set("owner",ob->query("id"));
			robber->do_change(ob);
			robber->move(room);
			robber->kill_ob(ob);
			ob->kill_ob(robber);
			break;
	}
         }	
	message_vision("$N扑在地上挣扎了几下，口中喷出几口"HIR"鲜血"NOR"，死了！\n",this_object());
	destruct(this_object());
	return;
}

