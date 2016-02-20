// ping.c 平一指

#include <ansi.h>
inherit NPC;

int ask_wu();
int ask_me();
int ask_heal();
int ask_poison();
int ask_over();
int ask_working();
string ask_work();
string ask_me1();
void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平一指。可是他性格古怪，不是什么人都医的。听说江湖中人有想向他学些济世之术的，也不知他肯不肯传授。\n");
	set("age", 65);

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("zhen_count", 1);
	set("shouwu_count", 2);
	set("count", 30);
	set("inquiry", ([
		"何首乌" : (: ask_wu :),
		"疗伤"   : (: ask_me :),
		"神药"   : (: ask_me1 :),
		"大力丸" : (: ask_me1 :),
		"潜能丹" : (: ask_me1 :),
		"治病"   : (: ask_heal :),
		"解毒"   : (: ask_poison :),
		"work"   : (: ask_working :),
		"工作"   : (: ask_working :),
		"分药"   : (: ask_working :),
		"报酬"   : (: ask_over :),
		"工资"   : (: ask_over :),   
		"over"   : (: ask_over :),   
		"针灸"   : (: ask_work :),
		"银针"   : (: ask_work :),
		"行医"   : (: ask_work :),
	]));
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"第八代弟子"NOR);
	create_family("黑木崖", 8, "弟子");

	setup();
	add_money("gold", 1);
	set("no_get",1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object(BOOK_DIR+"medicine1");
//	carry_object(BOOK_DIR+"medicine5");
}
void init()
{	
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting()&&!ob->query_temp("fengyaoover") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	int eff_qi, max_qi, hurt, i;


	tell_object(ob, "\n平一指抬头看了你几眼。\n");
	if (ob->query_condition("drunk"))
	{
		message_vision("平一指对$N说道：这位"+RANK_D->query_respect(ob)+"，看你脸红红的，一定是喝醉了！\n",ob);
	}
	if (ob->query_condition("killer"))
	{
		message_vision("平一指对$N说道：这位"+RANK_D->query_respect(ob)+"，官府正通缉你呢，你还是快走吧！！\n",ob);
		return;
	}

	if( !ob || environment(ob) != environment() ) return;
	eff_qi = ob->query("eff_qi");
	max_qi = ob->query("max_qi");
	if(100*eff_qi/max_qi<=50) hurt = 3;
	else if(100*eff_qi/max_qi<=70) hurt = 2;
	else if(100*eff_qi/max_qi<=95) hurt = 1;
	else hurt = 0;
	switch(hurt)
	{
		case 1 : message_vision("平一指满脸关切地对$N说道：这位"+RANK_D->query_respect(ob)+"看来受了点轻伤，我这由上好的丹药，不知是否要买些？\n",ob);
			break;
		case 2 : message_vision("平一指对$N说道：这位"+RANK_D->query_respect(ob)+"看来受伤不轻，买些丹药回去吧！\n",ob);
			break;
		case 3 : message_vision("平一指冷冷地对$N说道：这位"+RANK_D->query_respect(ob)+"伤重垂危，命不久矣，嘿嘿！\n",ob);
			break;
		default: command("look "+ob->query("id"));
			break;
	}
	if(!ob->query_temp("fengyaobegin") &&
		ob->query("combat_exp")>300 &&
		ob->query("combat_exp")<3000)
		say( "平一指又抬了抬眼皮，说道：小店正缺人手，这位" + RANK_D->query_respect(ob) + "有意的话，可以"CYN" 〖"HIR"ask ping about work"NOR CYN"〗\n"NOR);
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 ) return chinese_number(value) + "文钱";
	else if( value < 10000 ) return chinese_number(value/100) + "两白银" + (value%100? "又" + chinese_number(value%100) + "文钱": "");
	else return chinese_number(value/10000) + "两黄金" +( (value%10000)/100 ? chinese_number((value%10000)/100) + "两白银" : "") +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文钱": "");
}

int ask_wu()
{
	object ob = this_player ( ) ;

message_vision("平一指上上下下打量了$N一下：什么！何首乌？拿十两黄金来！\n",ob);
	ob->set_temp ("何首乌" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("何首乌"))
	{
		if (!(int)who->query_temp("mark/平"))
			who->set_temp("mark/平", 0);
		if (ob->query("money_id") && ob->value() >= 1000)
		{
			message_vision("平一指看来有点想指点$N一些关于济世之术的问题的意思。\n", who);
			who->add_temp("mark/平", ob->value() / 500);
		}
		else
			message_vision("平一指对$N说：医一人，杀一人，老夫就不收钱！\n", who);
		return 1;
	}
	if (query("shouwu_count") < 1)
	{
		message_vision("平一指对$N道：你来晚了。本店缺货！\n", who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 100000)
	{
		message_vision("平一指给了$N何首乌！\n" , who);
		add("shouwu_count", -1);
		this_player()->delete_temp("何首乌" );
		obj=new("/clone/medicine/vegetable/heshouwu");
		obj->move(this_player());
	}
	return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/平")) return 0;
	ob->add_temp("mark/平", -1);
	return 1;
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
	if(ob->query("shen")>0)
	{
		command("say 你们这些正派中人，我可不敢高攀！\n");
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
		message_vision("平一指喂$N服下一颗药丸，然后盘膝坐下，双掌贴着$N的背心。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			if (ob->query("family/family_name") != "黑木崖")
				ob->add("score",-200);
		        else ob->add("score",-100);    
		}
		me->add("count", -1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);		
		if (me->query("count")<1)  
		{
			where = environment(me);
			where->add("no_fight", 1);
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
	message_vision("大约过了一盅茶的时份，平一指慢慢地站了起来。\n",ob);
	command("say 你的伤势已经全好了,可以走啦。\n");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	me->add("count",20);
	where->add("no_fight", -1);
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

	if(ob->query("shen")>0)
	{       
		command("say 你们这些正派中人，我可不敢高攀！\n");
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
		if (ob->query("family/family_name") != "黑木崖")
	            ob->add("score",-200);
	        else ob->add("score",-100);    
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
	message_vision("大约一柱香过后，平一指让你喝下一碗刚熬好的热气腾腾的中药。\n",ob);
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

	if(ob->query("shen")>0)
	{
		command("say 你们这些正派中人，我可不敢高攀！\n");
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
		message_vision("平一指轻扣$N脉门，双眉深锁，随后喂$N服下一颗药丸，盘膝坐下，双掌贴着$N的背心，开始为$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			if (ob->query("family/family_name") != "黑木崖")
				ob->add("score",-300);
			else ob->add("score",-200);    
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
	message_vision("大约一柱香过后，$N吐出一口紫血，平一指慢慢地站了起来。\n",ob);
	command("say 你体内毒素已清，可以走啦。\n");
	return 1;
}

int ask_over()
{
	object mon, me = this_player();
	int bonus,exp,pot,tempp,kar;

	kar = me->query("kar");
	if (!me->query_temp("fengyaoover"))
	{
		message_vision("平一指惊讶的对$N说道：“哦！你再开什么玩笑，我这可不是养老院啊！”\n",me);
		return 1;
	}
	me->delete_temp("fengyaoover");
	if (me->query_temp("fengyaow"))
	{
		if(random(kar)>=11)
		{
			message_vision("平一指哼了一声，对$N说：“你是怎么搞的，乱分药，是想砸我的招牌吗？\n看在你还努力的份上还是赏你点钱吧。”\n",me);
			exp = 10 + random(20);
			mon = new("/clone/money/silver");
			mon->set_amount(exp);
			tell_object(me,HIW"平一指给了你" + chinese_number(exp) + "两白银。 \n"NOR);
			mon->move(me);
			me->delete_temp("fengyaow");
			return 1;
		}
		message_vision("平一指哼了一声，对$N说：你是怎么搞的，乱分药，是想砸我的招牌吗？\n",me);
		return 1;
	}
	message_vision("平一指笑着对$N说：“你还不错嘛，可以可以，这是你应该得的。”\n",me);
	exp = 10 + random(80);
	pot = 10 + random(50);
	bonus = (int) me->query("combat_exp");
	tempp = bonus;
	bonus += exp;
	me->set("combat_exp", bonus);
	bonus = (int) me->query("potential");
	bonus += pot;
	me->set("potential", bonus);
	mon = new("/clone/money/silver");
	mon->set_amount(exp);
	mon->move(me);
	me->start_busy(3);
	tell_object(me,"你被奖励了："HIR+chinese_number(exp)+NOR"点经验，"HIR+chinese_number(pot)+NOR"点潜能和"HIW+chinese_number(exp)+NOR"两白银。\n");
	bonus=(int) me->query("potential");
	return 1;
}
int ask_working()
{
	object me = this_player();

	if((int)(me->query("combat_exp")) > 3000 ||
		(int)(me->query("combat_exp")) < 300)
	{
		message_vision("平一指对$N说道：“阁下如此身手，小店劳烦不起。呵。。。呵。。。”\n",me);
		return 1;
	}
	if (me->query_temp("fengyaobegin"))
	{
		message_vision("平一指对$N说道：“你不是已经要了工作了，还不去干！”\n",me);
		return 1;
	}
	if ((int)(me->query("qi")) < random(30))        
	{
		message_vision("平一指对$N说道：“算了吧你，都这样了还想工作，把药分错了会出人命的。”\n",me);
		return 1;
	}
	if (me->query_temp("fengyaoover"))
	{
		message_vision("平一指对$N说道：“哦？ 你连自己的工资也不要。”\n",me);
		message_vision("平一指对$N说道：“好吧，既然这样我也就不勉强你了。”\n",me);
		message_vision("平一指对$N说道：“那你就到内室去帮我再分次药吧。”\n",me);
		me->delete_temp("fengyaow");
		me->delete_temp("fengyaoover");
		me->set_temp("fengyaobegin",1);
		return 1;
	}
	message_vision("平一指对$N说道：“好吧，那你就到内室去帮我分分药吧。”\n",me);
	me->set_temp("fengyaobegin",1);
	return 1;
}

string ask_me1()
{
	return "我...我不知道！";
}

string ask_work()
{
	object ob, me = this_player();

	if (present("yin zhen", me))
		return "你不是有银针了么？还来找我干嘛？";
	if (query("zhen_count") < 1)
		return "你来晚了，我的银针已经送人了。";
	if (me->query_skill("medicine", 1) < 50)
		return "你也想行医？那也得看是不是那块料啊。";
	if (me->query("medicine_count") < 50)
		return "你想行医，先得把药熬好，熟能生巧，磨刀不误砍柴功，这个道理你也知道，别贪多勿得的。";
	ob = new("/clone/misc/yinzhen");
	ob->move(me);
	add("zhen_count", -1);
	if (me->query_skill("acupuncture",1) > 0)
	{
		return "想行医？这针你先拿去用吧。可别辱没了我“医一人杀一人”的名头。";
	}
	else
	{
		me->set_skill("acupuncture", 1);
		return "初次行医吧？我来教你点针灸术吧。这样你就可以带针上路了。";
	}
}
