// dubi.c 独臂神尼

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);

void create()
{
	set_name("独臂神尼", ({ "dubi shenni", "dubi" }));
	set("gender", "女性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("no_get", 1);
	set("long", "这是一位白衣女尼，手握拂尘，目视前方。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住她迷人的风采。\n");
	set("combat_exp", 1000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("whip", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 90);
	set_skill("qiufeng-chenfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip", "qiufeng-chenfa");
	map_skill("parry", "qiufeng-chenfa");
	map_skill("dodge", "shenxing-baibian");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 100);
        set("inquiry", ([
                "阿珂" : "神尼叹了一口气，说道：她是我的得意弟子，\n人长得挺美，唉，只可惜被韦小宝骗去了。\n",
        ]) );
	create_family("铁剑门", 3, "弟子");
	setup();
        carry_object(WEAPON_DIR"whip/fuchen")->wield();
	carry_object(CLOTH_DIR"ni-cloth")->wear();
	carry_object(CLOTH_DIR"ni-shoe")->wear();
	add_money("gold", 2);
}

void init()
{
	::init();
	add_action("do_skills","skills");
	add_action("do_skills","cha");
//greeting();
	remove_call_out("greeting");
	call_out("greeting", 1, this_player() );
}

int recognize_apprentice(object ob)
{
	if ((ob->query("weiwang")+ob->query("meili"))<60)
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+"你我素不相识，为什么我一定要教你呢？ \n"); 
		return 0;
	}
	return 1;	
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="dubi" ) return 0;
	if(wizardp(ob)) return 0;
	if (ob->query("weiwang")<60)
	{
		message_vision("$N摇了摇头。\n",this_object());
		write("白衣女尼说道：你怎么能看我的武功呢？\n");
		return 1;
	}
	command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"  基本轻功 (dodge)                         - 深不可测 150/    \n"+
"  基本内功 (force)                         - 一代宗师  90/    \n"+
"  基本招架 (parry)                         - 一代宗师  90/    \n"+
"  基本拳脚 (unarmed)                       - 一代宗师  90/    \n"+
"  基本鞭法 (whip)                          - 深不可测 150/    \n"+
"□秋风尘法 (qiufeng-chenfa)                - 深不可测 150/    \n"+
"□神行百变 (shenxing-baibian)              - 深不可测 150/    \n");
	return 1;
}

void greeting(object ob)
{
	int i;
  int exp,pot,score;
  object me=ob;
	object man,*obj;

	man=this_object();
	message_vision("$N踏进屋来，只见地上女尼横陈，喘息不止。\n",ob);		
	if( !ob || environment(ob) != environment()) return;
    
	if((int)ob->query_temp("hastrystab")==6)
	{
		message_vision(HIC "$N踏进屋来，只见地上尸体横陈，一个女尼喘息不止。\n" NOR,ob);		
		ob->delete_temp("hastrystab");
		ob->delete_temp("warned2");
		message_vision("\n白衣女尼对$N说道：“多谢这位"+RANK_D->query_respect(ob)+ "拔刀相助，贫尼感激不尽，无以为报。\n这里有一套神行百变身法，你若愿学，贫尼定倾囊以授。”\n",ob);
	  if (!me->query("skybook/luding/dubi"))
  	{
  	 me->set("skybook/luding/dubi",1);
  	 exp=500+random(1000);
     pot=exp/2;
     score=pot/2;
     me->add("combat_exp",exp);
     me->add("potential",pot);
     	tell_object(me,HIC"你成功得到了独臂神尼的信任！\n在这次历练中你获得了"+
     	         chinese_number(exp)+"点经验、"+
               chinese_number(pot)+"点潜能以及"+
               chinese_number(score)+"点江湖阅历。\n\n"NOR);

  	}
		if(ob->query("weiwang")<60)
		{
			ob->add("weiwang",10);
			message_vision(HIC "$N的江湖威望提高了！\n" NOR,ob);
			command("tell "+ob->query("id")+" 你现在的江湖威望是 " +(string)(ob->query("weiwang")));
			return ;
		}
		message_vision(HIC "白衣女尼对$N微微一笑。\n" NOR,ob);		
		return;
	}
	obj = all_inventory(environment(ob));
	for(i=0; i<sizeof(obj); i++)
	{
		if( !living(obj[i]) || userp(obj[i]) || obj[i]==man ) continue;
		if( !userp(obj[i]) )
		{ 
/*			man->set_leader(obj[i]);
			man->kill_ob(obj[i]);
			obj[i]->fight_ob(man);
*/
//			man->set_leader(obj[i]);
			man->fight_ob(obj[i]);
			obj[i]->kill_ob(man); 
			//原来是独臂主动杀喇嘛 所以每次更新都会杀一个喇嘛
			//时间长了满地的戒刀 而且造成玩家凑不齐6个喇嘛 （ci wall要求杀6个）
		}
	}
	return ;
}
