// afrog.c

#include <ansi.h>
inherit NPC;

int ask_me();
int ask_heal();
int ask_poison();

void create()
{
	set_name("青蛙", ({ "afrog" }));
	set("title", "诊所医生");
	set("gender", "男性");
	set("long", "青蛙抬头看了你一眼，眼角流露出平和的笑容，让再紧张的病人见到心情也随之平静了许多。\n");
	set("age", 25);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("count", 30);
	set("inquiry", ([
		"疗伤"   : (: ask_me :),
		"治病"   : (: ask_heal :),
		"解毒"   : (: ask_poison :),
	]));

	set("party/party_name", HIB"华山派"NOR);
	set("party/rank", HIW"第二代弟子"NOR);
	create_family("华山派", 2, "弟子");
	setup();

	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;

	if(me->is_fighting())
	{
		command("say 我现在没空！\n");
		return 1;
	}
	if(me->query("count") < 1)
	{
		command("say 伤药都用完了，我还没来得及配，你一会再来吧。\n");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{
		command("say 你这点江湖阅历，也想让我为你疗伤？\n");
		return 1;
	}
		
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?"+ob->query("id"));
		command("say 你没有受任何伤啊？\n");
		return 1;
	}
	else
	{
		message_vision("青蛙喂$N服下一颗药丸，然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		        ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{
			where = environment(me);
			remove_call_out("newyao");
			call_out("newyao",600,me);
		}
		return 1;
	}
}

int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("大约过了一盅茶的时份，青蛙慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了,可以走啦。\n");
	return 1;
}

int newyao(object me)
{
	object where = environment(me);
	me->add("count",20);
	return 1;
}
	
int ask_heal()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting())
        {
		command("say 我现在没空！\n");
		return 1;
	}

	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{       
		command("say 你这点江湖阅历，也想让我为你治病？\n");
		return 1;
	}
		
	if( ob->query_condition("ill_kesou") ||
		ob->query_condition("ill_zhongshu") ||
		ob->query_condition("ill_shanghan") ||
		ob->query_condition("ill_dongshang") ||
		ob->query_condition("ill_fashao"))
	{
		message_vision("平一指轻扣$N脉门，略一思索，随后转身从药篓里取出几味草药，开始为$N熬药。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);		
		return 1;
	}
	
	else
	{
		command("?"+ob->query("id"));
		command("say 看你的气色，并没有生病啊？\n");
		return 1;
	}
	
}
int recover_II(object ob)
{
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
	message_vision("大约一柱香过后，青蛙让你喝下一碗刚熬好的热气腾腾的中药。\n",ob);
	command("say 你的身体已无大碍,可以走啦。\n");
	return 1;
}

int ask_poison()
{
	object ob = this_player();
	object me = this_object();
	object where;

        if(me->is_fighting())
	{
		command("say 我现在没空！\n");
		return 1;
	}

	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{
		command("say 你这点江湖阅历，也想让我为你解毒？\n");
		return 1;
	}
		
	if(ob->query_condition("chanchu_poison") ||
		ob->query_condition("drunk") ||
		ob->query_condition("flower_poison") ||
		ob->query_condition("ice_poison") ||
		ob->query_condition("iceshock") ||
		ob->query_condition("rose_poison") ||
		ob->query_condition("scorpion_poison") ||
		ob->query_condition("slumber_drug") ||
		ob->query_condition("snake_poison") ||
//		ob->query_condition("ss_poison") ||
		ob->query_condition("wugong_poison") ||
//		ob->query_condition("xx_poison") ||
		ob->query_condition("xiezi_poison") ||
		ob->query_condition("zhizhu_poison") ||
		ob->query_condition("zhua_poison") ||
		ob->query_condition("ice_sting"))
	{
		message_vision("青蛙轻扣$N脉门，双眉深锁，随后喂$N服下一颗药丸，盘膝坐下，双掌贴着$N的背心，开始为$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			ob->add("score",-200);    
		}
		me->add("count", -1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);		
		return 1;
	}
	else
	{
		command("?"+ob->query("id"));
		command("say 看来我帮不了你什么忙了！\n");
		return 1;
	}
}
int recover_III(object ob)
{
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
	message_vision("大约一柱香过后，$N吐出一口紫血，青蛙慢慢地站了起来。\n",ob);
	command("say 你体内毒素已清，可以走啦。\n");
	return 1;
}