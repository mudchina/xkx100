// init.h 定义黄河帮高手检查，自己消失的时间
#define A_TIME 20

void init()
{
	object me, ob, *obs;
	mapping skl;
	string *skillname;
	int i, j, exp, neili, skilllvl;
	me=this_object();

	obs = all_inventory(environment(me)); 
	exp = 0;
	neili = 0;
	skilllvl = 0;
	for (i=0; i<sizeof(obs); i++)
	{
		if( !living(obs[i]) || obs[i]==me ) continue;
		if (exp < obs[i]->query("combat_exp"))
			exp = obs[i]->query("combat_exp");
		if (neili < obs[i]->query("max_neili"))
			neili = obs[i]->query("max_neili");
		skl = obs[i]->query_skills();
		if (!sizeof(skl)) continue;
		skillname = sort_array( keys(skl), (: strcmp :) );
		for (j=0; j<sizeof(skl); j++)
		{
			if (skilllvl < skl[skillname[j]])
				skilllvl = skl[skillname[j]];
		}
	}

	if( exp <= 0 ) exp = random(3000) + 1;
		else exp = exp + random(10000) - 7000; 
	exp = exp/2 + random(exp/2);
	me->set("combat_exp", exp);

	if( neili <= 0 ) neili = random(100) + 1;
		else neili = neili + random(200) - 100; 
	me->set("max_neili", neili);
	me->set("neili", neili);
	me->set("jiali", (int)(neili/80 + random(neili/80)));

	if( skilllvl <= 0 ) skilllvl = random(3) + 6;
	skilllvl = skilllvl / 2 + random(skilllvl/3);
	me->set_skill("tiyunzong", skilllvl + random(10) - 6);
	me->set_skill("liangyi-jian", skilllvl + random(10) - 6);
	me->set_skill("taiji-jian", skilllvl + random(10) - 6);
	me->set_skill("taiji-quan", skilllvl + random(10) - 6);
	me->set_skill("taiji-shengong", skilllvl + random(10) - 6);
	skilllvl = (int) (skilllvl / 3 * 2);
	me->set_skill("force", skilllvl + random(10) - 4);
	me->set_skill("dodge", skilllvl + random(10) - 4);
	me->set_skill("parry", skilllvl + random(10) - 4);
	me->set_skill("sword", skilllvl + random(10) - 4);
	me->set_skill("unarmed", skilllvl + random(10) - 4);

	me->map_skill("dodge", "tiyunzong");
	me->map_skill("force", "taiji-shengong");
	me->map_skill("unarmed", "taiji-quan");
	me->map_skill("sword", "taiji-jian");
	me->map_skill("parry", "liangyi-jian");

	remove_call_out("do_check");
	call_out("do_check", 0);
	remove_call_out("do_wait");
	call_out("do_wait",A_TIME);
}

void do_check()
{
	object me = this_object();
	object ob;

	if (! living(me) || me->is_fighting() )
	{
	       if( ! living(me)&& ob = present("biao tou",environment(me))) 
                { 
                    message_vision("$N咬牙切齿地对着天空大叫：“贼老天！”\n",me);
                    ob -> add("combat_num",1);
                    return;
                }
                remove_call_out("do_check");
		call_out("do_check",0);
	}
	else
	{
		if( !ob = present("biao tou",environment(me)))
		{
			remove_call_out("do_check");
			call_out("do_check",0);
		}
		else
		{
			if (! environment()->query("no_fight") )
			{
				me->set_leader(ob);
				message_vision("$N对着$n大喝一声：你这"+RANK_D->query_rude(ob)+"，拿命来！\n",me,ob);
				command("kill "+ob->query("id"));
			//	ob -> add("combat_num",1);
	               //       if(!ob->is_busy())  ob->start_busy(20); 
                                remove_call_out("do_jiefei");
				call_out("do_jiefei", 15);
			}
			else
			{
				me->set_leader(ob);
				remove_call_out("do_wait");
				call_out("do_wait", 10*A_TIME);
			}
		}
	}
}
void do_jiefei()
{
	object ob;
	object me = this_object();
	message_vision(HIY"$N冷笑道：哈哈，我的帮手来啦！\n"NOR,me);
	message_vision(HIR"猛地一阵脚步乱响，黄河帮劫匪冲了过来！\n"NOR,me);
	ob = new(__DIR__"jiefei");
	ob ->move(environment(me));
}
void do_wait()
{
	object ob;
	object me = this_object();

	if( ob = present("biao tou",environment(me)))
	{
		message_vision("$N冷笑道：镖头还在这呀。怎么充哑巴了？\n",this_object());
		command("kill "+ob->query("id"));
	}
	if (me->is_fighting() || !living(me) )
	{
		remove_call_out("do_wait");
		call_out("do_wait",A_TIME);
	}
	else
	{
		if (ob = present("corpse",environment(me)))
		{
			message_vision("$N狂笑道：“镖头既死，你没法交差，我可以回去交差了。”\n一阵风般不见了。\n",this_object());
			destruct(me);
		}
		else
		{
			message_vision("$N自言自语地说道：看来镖车不会从这里来了，我还是回去吧。\n$N满面无奈地向远处走了开去。\n",this_object());
			destruct(me);
		}
	}
}

void killed_enemy(object victim)
{
	object me = this_object();

	if (victim->query("id") == "biao tou")
	{
		message_vision("$N仰天狂笑一声：哈哈，“终于得手了！我看你怎么交差！”几个起落，飞身不见了。\n",me);
		destruct(me);
	}
}

