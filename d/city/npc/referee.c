// referee.c 公平子
//modified by sega 99/1/16
//在do_start和do_bihua里添加了 "biwu/perform_time"属性,用于
//perform和hubo间隔的判断.比武完毕取消.

inherit NPC;
#include <ansi.h>

int player11,player12,player21,player22;
int do_bihua(string arg);
string ask_me();
int do_halt();
int do_no();
int real=0;

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("no_get", 1);
	set("long",
		"这是一位仙风道骨的中年道人，早年云游四方，性好任侠，公正无私。\n");
	set("combat_exp",50000000);
	set("shen_type", 1);
	set("attitude", "friendly");

	set("apply/attack", 500);
	set("apply/defense", 500);

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);

	set_skill("force", 500);
	set_skill("unarmed", 500);
	set_skill("sword",500);
	set_skill("parry",500);
	set_skill("dodge", 500);

	set("inquiry", ([
		"比武大会" : (: ask_me :),
		"武林大会" : (: ask_me :),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	::init();
	add_action("do_start", "start");
	add_action("do_bihua", "bihua");
	add_action("do_bihua", "bi");
	add_action("do_bihua", "hit");
	add_action("do_bihua", "kill");
	add_action("do_bihua", "fight");
	add_action("do_bihua", "qiecuo");
	add_action("do_halt", "halt");
	add_action("do_halt", "h");
	add_action("do_no", "beg");
	add_action("do_no", "steal");
	add_action("do_no", "quanjia");
	add_action("do_no", "persuade");
	add_action("do_no", "touxi");
	add_action("do_no", "ansuan");
	add_action("do_no", "shexin");
	if( environment(this_object())->query("short") != "擂台" )
		this_object()->die();
}
string ask_me()
{
	object* ob;
	int i;
	ob = users();

	if ( !wizardp(this_player()) ) return "你无权召开比武大会！\n";
	for ( i=sizeof(ob); i>0; i-- ) {
		if (environment(ob[i-1]))
		{
			ob[i-1]->move("/d/city/wudao1");
			ob[i-1]->set_temp("view_leitai",1);
		}
	}

	return "好，现在比武大会正式开始，全体集合！\n";
}

int do_no()
{
	command("say " + "这里众目睽睽，岂能做此不才之事。\n");
	return 1;
}
int do_start(string arg)
{
	int i,j;
	string str1,str2;
	object *allob, ob1, ob2, old_target, where;
	mapping armors;
	object weapon;
	object armor;
	string *inv;

	if (!wizardp(this_player()))
	{
		command("say " + "比武要巫师发令才开始！\n");
		return 1;
	}
	if (!arg)
	{
		allob = all_inventory(environment(this_player()));
	  ob1 = this_object();
	  ob2 = this_player();

		j = 0;
		for ( i=sizeof(allob); i>0; i-- )
		{
			if ( userp(allob[i-1]) && !wizardp(allob[i-1]))
			{
				if (j == 0)
				{
					ob1 = allob[i-1];
					j = 1;
				}
				else ob2 = allob[i-1]; 
			}
		}
  }
  else
  {
  	if (sscanf(arg,"%s %s",str1,str2)==2)
  	{
  		ob1=present(str1,environment());
  	  ob2=present(str2,environment());
  	}
  }
  	if (!ob1 || !userp(ob1) || !ob2 || !userp(ob2))
  	 return notify_fail("这里没有这两个玩家。\n");
  
	if (ob1 == ob2) return notify_fail("只有一个人不能比武。\n");

	if (objectp(weapon=ob1->query_temp("weapon")) && weapon->query("weapon_prop/damage")>100)
		return notify_fail(ob1->query("name")+"装备了违规武器。\n");

	if (objectp(weapon=ob2->query_temp("weapon")) && weapon->query("weapon_prop/damage")>100)
		return notify_fail(ob2->query("name")+"装备了违规武器。\n");
	
	if (objectp(armor = ob1->query_temp("armor")["cloth"]))
		if (armor->query("armor_prop/armor")>50)
		return notify_fail(ob1->query("name")+"装备了违规防具。\n");

	if (objectp(armor = ob1->query_temp("armor")["cloth"]))
		if (armor->query("armor_prop/armor")>50)
		return notify_fail(ob2->query("name")+"装备了违规防具。\n");
  
	inv = keys(ob1->query_temp("armor"));
	for (i=0;i<sizeof(inv);i++)
		if (inv[i]!="cloth") ob1->query_temp("armor/"+inv[i])->unequip();

	inv = keys(ob2->query_temp("armor"));
	for (i=0;i<sizeof(inv);i++)
		if (inv[i]!="cloth") ob2->query_temp("armor/"+inv[i])->unequip();
	
	ob1->delete_temp("halted");
	ob2->delete_temp("halted");
  real=1;
	ob1->set("qi",(int)ob1->query("max_qi"));
	ob1->set("eff_qi",(int)ob1->query("max_qi"));
	ob1->set("neili",2*(int)ob1->query("max_neili"));
	ob2->set("qi",(int)ob2->query("max_qi"));
	ob2->set("eff_qi",(int)ob2->query("max_qi"));
	ob2->set("neili",2*(int)ob2->query("max_neili"));

	remove_call_out("check");
	call_out("check", 0, ob1, ob2);
//perform时间间隔限制
	ob1->set_temp("biwu/perform_time",time());
	ob2->set_temp("biwu/perform_time",time());

	remove_call_out("fighting");
	call_out("fighting", 0, ob1, ob2);

	return 1;
}
int do_bihua(string arg)
{
	object ob1, ob2;
	object old_target;

	ob1 = this_player();

	if( !arg || arg=="" ) return 0;

	if ( arg == "gongping zi" || arg == "zi" || arg == "referee" )
	{
		command("say " + "你不能跟我比划！");
		return 1;
	}

	if ( this_object()->query_temp("busy") )
		return notify_fail("每次只能有两人参加比武。\n");

	if (!ob2 = present(arg,environment(ob1)) )
		return notify_fail("你想跟谁比划？\n");
	if (ob1 == ob2) return notify_fail("你不能攻击自己。\n");
	if (!userp(ob1) || !userp(ob2))
		return notify_fail("比武是两个玩家之间的事。\n");
	if (ob1->query("max_jing") > ob1->query("jing"))
		return notify_fail("你受伤太重不能比武。\n");
	if (ob1->query("max_jing") > ob1->query("eff_jing"))
		return notify_fail("你受伤太重不能比武。\n");
	if (ob1->query("max_qi") > ob1->query("qi"))
		return notify_fail("你受伤太重不能比武。\n");
	if (ob1->query("max_qi") > ob1->query("eff_qi"))
		return notify_fail("你受伤太重不能比武。\n");
	if (ob2->query("max_jing") > ob2->query("jing"))
		return notify_fail("对方受伤太重不能比武。\n");
	if (ob2->query("max_jing") > ob2->query("eff_jing"))
		return notify_fail("对方受伤太重不能比武。\n");
	if (ob2->query("max_qi") > ob2->query("qi"))
		return notify_fail("对方受伤太重不能比武。\n");
	if (ob2->query("max_qi") > ob2->query("eff_qi"))
		return notify_fail("对方受伤太重不能比武。\n");
/* 允许玩家自比
	command("say " + "比武要裁判发令才开始！\n");
	return 1;
*/

	if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
		message_vision("\n$N对着$n说道"
			+ RANK_D->query_self(ob1)
			+ ob1->name() + "领教"
			+ RANK_D->query_respect(ob2) + "的高招！\n\n", ob1, ob2);
		if( objectp(old_target = ob1->query_temp("pending/fight")) )
			tell_object(old_target, YEL + ob1->name() + "取消了和你比试的念头。\n" NOR);
		ob1->set_temp("pending/fight", ob2);
		tell_object(ob2, YEL "如果你愿意和对方进行比试请你也对" + ob1->name() + "("+(string)ob1->query("id")+")"+ "下一次 bihua 指令。\n" NOR);

		write(YEL "由於对方是由玩家控制的人物你必须等对方同意才能进行比试。\n" NOR);
		return 1;
	}
  real=0;
	ob1->delete_temp("halted");
	ob2->delete_temp("halted");

	remove_call_out("check");
	call_out("check", 0, ob1, ob2);

//	ob1->set("qi",(int)ob1->query("max_qi"));
//	ob2->set("qi",(int)ob2->query("max_qi"));

//perform时间间隔限制

	ob1->set_temp("biwu/perform_time",time());
	ob2->set_temp("biwu/perform_time",time());

	remove_call_out("fighting");
	call_out("fighting",0, ob1, ob2);

	return 1;

}

void fighting(object ob1, object ob2)
{
	if (!objectp(ob1) || !objectp(ob2) ||
	environment()!=environment(ob1) || 
	environment()!=environment(ob2))
	{
		if (objectp(ob1)) ob1->delete_temp("biwu/perform_time");
		if (objectp(ob2)) ob2->delete_temp("biwu/perform_time");
		return;		
	}
	if (real==1)
	{
	  real=-1;
		ob1->kill_ob(ob2);
  	ob2->kill_ob(ob1);
  }
  else
  {
		ob1->fight_ob(ob2);
		ob2->fight_ob(ob1);
  }
}

void check(object ob1, object ob2)
{
	string str;
	
	this_object()->set_temp("busy",1);
	command("chat " + ob1->query("name")
		+ "与" + ob2->query("name") + "，现在擂台上开始比武夺帅！\n");
//	command("sys 双方当前气："+ob1->query("id")+" - "+ob1->query("qi")+" : "+ob2->query("id")+" - "+ob2->query("qi"));
//	command("sys 双方当前精："+ob1->query("id")+" - "+ob1->query("jing")+" : "+ob2->query("id")+" - "+ob2->query("jing"));
//	command("sys 双方当前内力："+ob1->query("id")+" - "+ob1->query("neili")+" : "+ob2->query("id")+" - "+ob2->query("neili"));
	str = "\n";
	str += sprintf(HIY"比武开始 %|8s %|8s \n",ob1->query("id"),ob2->query("id"));
	str += sprintf(HIG"精气     %4d/%-4d %4d/%-4d \n",ob1->query("jing"),ob1->query("max_jing"),ob2->query("jing"),ob2->query("max_jing"));
	str += sprintf(HIC"气血     %4d/%-4d %4d/%-4d \n",ob1->query("qi"),ob1->query("max_qi"),ob2->query("qi"),ob2->query("max_qi"));
	str += sprintf(HIW"内力     %4d/%-4d %4d/%-4d "NOR,ob1->query("neili"),ob1->query("max_neili"),ob2->query("neili"),ob2->query("max_neili"));
	CHANNEL_D->do_channel(this_object(),"sys",str);
	player11=(int)ob1->query("jing");
	player12=(int)ob1->query("neili");
	player21=(int)ob2->query("jing");
	player22=(int)ob2->query("neili");
	remove_call_out("observe");
	call_out("observe", 1, ob1, ob2);
}

int observe(object ob1,object ob2)
{
	object ob;
	int obqi1, obmqi1, obqi2, obmqi2;
	string str;

	if (!objectp(ob1) || !objectp(ob2) )
	{
			this_object()->delete_temp("busy");
			return 1;
	}
	if(ob1->is_fighting() || ob2->is_fighting())
	{
		ob1->fight_ob(ob2);
		ob2->fight_ob(ob1);
		call_out("observe", 1, ob1, ob2);
		return 1;
	}

	this_object()->delete_temp("busy");
	ob1->delete_temp("pending/fight");
	ob2->delete_temp("pending/fight");
//取消perform限制
	ob1->delete_temp("biwu/perform_time");
	ob2->delete_temp("biwu/perform_time");


	if(!present(ob1, environment()) )
	{
		command("chat "+ob1->query("name")+"("+ob1->query("id")+")"+"被"+ob2->query("name")+"("+ob2->query("id")+")"+"打落擂台了！\n");
    if (real==-1)
    {
    	real=0;
      ob1->remove_all_killer();
      ob1->remove_all_enemy();
      ob2->remove_all_killer();
      ob2->remove_all_enemy();
    	ob1->move(environment(this_object()),1);
    	if (ob1->remove_call_out("revive")) ob1->revive();
      ob1->set("jing",(int)ob1->query("max_jing"));
      ob1->set("eff_jing",(int)ob1->query("max_jing"));
      ob1->set("neili",(int)ob1->query("max_neili"));
      ob1->set("qi",(int)ob1->query("max_qi"));
      ob1->set("eff_qi",(int)ob1->query("max_qi"));

      ob2->set("jing",(int)ob2->query("max_jing"));
      ob2->set("eff_jing",(int)ob2->query("max_jing"));
      ob2->set("neili",(int)ob2->query("max_neili"));
      ob2->set("qi",(int)ob2->query("max_qi"));
      ob2->set("eff_qi",(int)ob2->query("max_qi"));
		}
		return 1;
	}

	if(!present(ob2, environment()) )
	{
		command("chat "+ob2->query("name")+"("+ob2->query("id")+")"+"被"+ob1->query("name")+"("+ob1->query("id")+")"+"踢下擂台了！\n");
    if (real==-1)
    {
    	real=0;
      ob2->remove_all_killer();
      ob2->remove_all_enemy();
      ob1->remove_all_killer();
      ob1->remove_all_enemy();
    	ob2->move(environment(this_object()),1);
    	if (ob2->remove_call_out("revive"))
       	ob2->revive();
      ob1->set("jing",(int)ob1->query("max_jing"));
      ob1->set("eff_jing",(int)ob1->query("max_jing"));
      ob1->set("neili",(int)ob1->query("max_neili"));
      ob1->set("qi",(int)ob1->query("max_qi"));
      ob1->set("eff_qi",(int)ob1->query("max_qi"));

      ob2->set("jing",(int)ob2->query("max_jing"));
      ob2->set("eff_jing",(int)ob2->query("max_jing"));
      ob2->set("neili",(int)ob2->query("max_neili"));
      ob2->set("qi",(int)ob2->query("max_qi"));
      ob2->set("eff_qi",(int)ob2->query("max_qi"));
		}
		return 1;
	}

	if(ob1->query_temp("halted"))
	{
		ob1->delete_temp("halted");
		command("chat "+ob1->query("name")+"("+ob1->query("id")+")"+"中途放弃比武！\n");
		return 1;
	}
	if(ob2->query_temp("halted"))
	{
		ob2->delete_temp("halted");
		command("chat "+ob2->query("name")+"("+ob2->query("id")+")"+"不愿继续比武了！\n");
		return 1;
	}
	obqi1 = ob1->query("qi")*2;
	obmqi1 = ob1->query("max_qi");
	obqi2 = ob2->query("qi")*2;
	obmqi2 = ob2->query("max_qi");
	if( (obqi1 > obmqi1) && (obqi2 > obmqi2) )
	{
		command("chat "+ob1->query("name")+"与"+ob2->query("name")+"比武不分胜负！继续再比一场决出胜负！\n");
	}
	if( (obqi1 > obmqi1) && (obqi2 <= obmqi2) )
	{
		command("chat "+ob1->query("name")+"("+ob1->query("id")+")"+"比武战胜"+ob2->query("name")+"("+ob2->query("id")+")"+"！\n");
	}
	if( (obqi1 <= obmqi1) && (obqi2 > obmqi2) )
	{
		command("chat "+ob2->query("name")+"("+ob2->query("id")+")"+"比武打败了"+ob1->query("name")+"("+ob1->query("id")+")"+"！\n");
	}
	if( (obqi1 <= obmqi1) && (obqi2 <= obmqi2) )
	{
		if( obqi1 < obqi2 )
		{
			command("chat "+ob2->query("name")+"("+ob2->query("id")+")"+"比武打倒了"+ob1->query("name")+"("+ob1->query("id")+")"+ "！\n");
		}
		else
		{
			command("chat "+ob1->query("name")+"("+ob1->query("id")+")"+"比武险胜了"+ob2->query("name")+"("+ob2->query("id")+")"+"！\n");
		}
	}
	str = "\n";
	str += sprintf(HIY"比武结束 %|8s %|8s \n",ob1->query("id"),ob2->query("id"));
	str += sprintf(HIG"精气     %4d/%-4d %4d/%-4d \n",ob1->query("jing"),ob1->query("max_jing"),ob2->query("jing"),ob2->query("max_jing"));
	str += sprintf(HIC"气血     %4d/%-4d %4d/%-4d \n",ob1->query("qi"),ob1->query("max_qi"),ob2->query("qi"),ob2->query("max_qi"));
	str += sprintf(HIW"内力     %4d/%-4d %4d/%-4d "NOR,ob1->query("neili"),ob1->query("max_neili"),ob2->query("neili"),ob2->query("max_neili"));
	CHANNEL_D->do_channel(this_object(),"sys",str);
//	command("sys 双方余气："+ob1->query("id")+" - "+obqi1/2+" : "+ob2->query("id")+" - "+obqi2/2);
//	command("sys 双方余精："+ob1->query("id")+" - "+ob1->query("jing")+" : "+ob2->query("id")+" - "+ob2->query("jing"));
//	command("sys 双方余内力："+ob1->query("id")+" - "+ob1->query("neili")+" : "+ob2->query("id")+" - "+ob2->query("neili"));

	ob1->set("jing",(int)ob1->query("max_jing"));
	ob1->set("eff_jing",(int)ob1->query("max_jing"));
	ob1->set("jing",player11);
	ob1->set("neili",player12);
	ob1->set("qi",(int)ob1->query("max_qi"));
	ob1->set("eff_qi",(int)ob1->query("max_qi"));

	ob2->set("jing",(int)ob2->query("max_jing"));
	ob2->set("eff_jing",(int)ob2->query("max_jing"));
	ob2->set("jing",player21);
	ob2->set("neili",player22);
	ob2->set("qi",(int)ob2->query("max_qi"));
	ob2->set("eff_qi",(int)ob2->query("max_qi"));

	return 1;

}

int do_halt()
{
	object me = this_player();

	if (me->is_fighting()) me->set_temp("halted",1);
	return 0;
}
