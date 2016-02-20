// xuemuhua.c 薛慕华
// Modified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;

int ask_me();
int ask_heal();
int ask_poison();

void create()
{
	set_name("薛慕华", ({ "xue muhua", "xue" }));
	set("long", "他就是号称阎王敌的神医——薛慕华，据说他精通医理，可以起死回生。\n");
	set("gender", "男性");
	set("nickname","“函谷八友”神医");
	set("age", 37);
	set("no_get", "1");
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("inquiry", ([
		"疗伤" : (:ask_me:),
		"治病"	: (: ask_heal :),
		"解毒"	: (: ask_poison :),
	]) );

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 320000);
	set("score", 80000);

	set("count", 30);
	set_skill("medicine", 150);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("hand", 60);
	set_skill("parry", 60);
	set_skill("lingboweibu", 60);
	set_skill("beiming-shengong", 60);
	set_skill("zhemei-shou", 60);
	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	map_skill("parry", "ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	set("env/wimpy", 60);

	create_family("逍遥派", 3, "弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
	command("recruit " + ob->query("id"));
}

int ask_me()
{
	object ob=this_player();
        object me = this_object();
	object where;
        if(me->is_fighting() || me->query_temp("busy"))
          {
            command("say 我现在没空！");
            return 1;
          }       
   
         if(me->query("count") < 1)
	{
		command("say 伤药都用完了，我还没来得及配，你一会再来吧。");
		return 1;
	}
        if(ob->query("shen")<0)
	{       
		command("say 你心术不正，我可不敢为你疗伤！");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100500)
	{       
		command("say 你这点江湖阅历，也想让我为你疗伤？");
		return 1;
	}	
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")
	  &&(int)ob->query("eff_jing") == (int)ob->query("max_jing"))
	{
		command("? "+ob->query("id"));     
		command("say 你没有受任何伤啊？");
		return 1;
	}
	else
	{
		message_vision("薛慕华喂$N服下一颗药丸，然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		if( ob->query("combat_exp")>100500)
		{
		if (ob->query("family/family_name") != "逍遥派")
	            ob->add("score",-200);
	        else ob->add("score",-100);
  		}
		me->set_temp("busy",1);
		ob->start_busy(2);
		add("count",-1);
		remove_call_out("recover");
		call_out("recover",2,ob);
                if (me->query("count")<1)  
		{  where = environment(me);
		   where->add("no_fight", 1);
		   remove_call_out("newyao");
		   call_out("newyao",1800,me);
		 }
		return 1;
	}
}


int recover(object ob)
{
	this_object()->delete_temp("busy");
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("大约过了一盅茶的时分，薛慕华慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了，可以走啦。");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	this_object()->delete_temp("busy");
	me->add("count",30);
	where->add("no_fight", -1);
	return 1;
}
	
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting() || me->query_temp("busy"))
         {
           command("say 我现在没空！");
           return 1;
         }

	if(ob->query("shen")<0)
	{       
		command("say 你心术不正，我可不敢为你治病！");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{       
		command("say 你这点江湖阅历，也想让我为你治病？");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou")
	    || ob->query_condition("ill_zhongshu")
	    ||ob->query_condition("ill_shanghan")
	    ||ob->query_condition("ill_dongshang")
	    ||ob->query_condition("ill_fashao"))
	{
		message_vision("薛慕华轻扣$N脉门，略一思索，随后转身从药篓里取出几味草药，开始为$N熬药。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "逍遥派")
	            ob->add("score",-200);
	        else ob->add("score",-100);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say 看你的气色，并没有生病啊？");
		return 1;
	}
	
}
int recover_II(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("ill_kesou"))
		ob->clear_condition("ill_kesou",0);
	if (ob->query_condition("ill_zhongshu"))
		ob->clear_condition("ill_zhongshu",0);
	if (ob->query_condition("ill_shanghan"))
		ob->clear_condition("ill_shanghan",0);
	if (ob->query_condition("ill_dongshang"))
		ob->clear_condition("ill_dongshang",0);
	if (ob->query_condition("ill_fashao"))
		ob->clear_condition("ill_fashao",0);
	message_vision("大约一柱香过后，薛慕华让你喝下一碗刚熬好的热气腾腾的中药。\n",ob);
	command("say 你的身体已无大碍,可以走啦。");
	return 1;
}

	
int ask_poison()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting() || me->query_temp("busy"))
         {
           command("say 我现在没空！");
           return 1;
         }

	if(ob->query("shen")<0)
	{       
		command("say 你心术不正，我可不敢为你解毒！");
		return 1;
	}
	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{       
		command("say 你这点江湖阅历，也想让我为你解毒？");
		return 1;
	}
		
	if( ob->query_condition("chanchu_poison")
	    || ob->query_condition("drunk")
	    ||ob->query_condition("flower_poison")
	    ||ob->query_condition("ice_poison")
	    ||ob->query_condition("iceshock")
	    || ob->query_condition("rose_poison")
	    ||ob->query_condition("scorpion_poison")
	    ||ob->query_condition("slumber_drug")
	    || ob->query_condition("snake_poison")
	//   ||ob->query_condition("ss_poison")
	    ||ob->query_condition("wugong_poison")
	//   || ob->query_condition("xx_poison")
	    ||ob->query_condition("xiezi_poison")
	    ||ob->query_condition("zhizhu_poison")
	    || ob->query_condition("zhua_poison")
	    ||ob->query_condition("ice_sting"))
	{
		message_vision("薛慕华轻扣$N脉门，双眉深锁，随后喂$N服下一颗药丸，盘膝坐下，双掌贴着$N的背心，开始为$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "逍遥派")
	            ob->add("score",-300);
	        else ob->add("score",-200);    
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	
	else
	{
		command("? "+ob->query("id"));
		command("say 看来我帮不了你什么忙了！");
		return 1;
	}
	
}
int recover_III(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("chanchu_poison"))
		ob->clear_condition("chanchu_poison",0);
	if (ob->query_condition("drunk"))
		ob->clear_condition("drunk",0);
	if (ob->query_condition("flower_poison"))
		ob->clear_condition("flower_poison",0);
	if (ob->query_condition("ice_poison"))
		ob->clear_condition("ice_poison",0);
	if (ob->query_condition("iceshock"))
		ob->clear_condition("iceshock",0);
	if (ob->query_condition("rose_poison"))
		ob->clear_condition("rose_poison",0);
	if (ob->query_condition("scorpion_poison"))
		ob->clear_condition("scorpion_poison",0);
	if (ob->query_condition("slumber_drug"))
		ob->clear_condition("slumber_drug",0);
	if (ob->query_condition("snake_poison"))
		ob->clear_condition("snake_poison",0);
//	if (ob->query_condition("ss_poison"))
//		ob->clear_condition("ss_poison",0);
	if (ob->query_condition("wugong_poison"))
		ob->clear_condition("wugong_poison",0);
//	if (ob->query_condition("xx_poison"))
//		ob->clear_condition("xx_poison",0);
	if (ob->query_condition("xiezi_poison"))
		ob->clear_condition("xiezi_poison",0);
	if (ob->query_condition("zhizhu_poison"))
		ob->clear_condition("zhizhu_poison",0);
	if (ob->query_condition("zhua_poison"))
		ob->clear_condition("zhua_poison",0);
	if (ob->query_condition("ice_sting"))
		ob->clear_condition("ice_sting", 0);
	message_vision("大约一柱香过后，$N吐出一口紫血，薛慕华慢慢地站了起来。\n",ob);
	command("say 你体内毒素已清,可以走啦。");
	return 1;
}
