// Last Modified by Sir 11/18/2003
#include <ansi.h>
inherit NPC;

int do_copy(int maxpot,int type);

void create()
{
	set_name("蒙古大汉", ({ "menggu dahan","dahan"}));
	set("gender", "男性");
	seteuid(getuid());
	set("age", random(20) + 25);
	set("str", 30);
	set("con", 26);
	set("int", 20);
	set("dex", 26);
	set("combat_exp", 80000 + random(40000)); 
	set("attitude", "friendly");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_go","go");
}

int do_go(string arg)
{
	if (this_player()->query_condition("guojx_mis"))
	{
		write(HIR"蒙古奸细就在眼前，怎可临阵脱逃！\n"NOR);
		return 1;
	}
}
int accept_hit(object who)
{
	object me=this_object();
	if (who->query_condition("guojx_mis")) 
	{
		message_vision(CYN"$N加油！$N加油！\n"NOR,who);
		me->kill_ob(who);
		who->kill_ob(me);
		return 1;
	}
	else return notify_fail(HIY"想对付"HIR"蒙古奸细"HIY"？快去找郭靖大侠！\n"NOR);
}
int accept_fight(object who)	{return accept_hit(who);}
int accept_kill(object who)		{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}

int do_copy( int maxexp,int type)
{
	int skt,skl;
	object ob,weapon;
	ob = this_object();
	if(type==3)
	{
//		skl = 200 + random(50);
		ob->set("combat_exp", ( maxexp +random( maxexp /2)));
		skl=ceil( pow( query("combat_exp")*10.0, 0.333333));
//		ob->set("max_qi", 3000);
//		ob->set("eff_qi", 3000);
//		ob->set("qi",     3000);
		ob->set("max_qi", 2500);
		ob->set("eff_qi", 2500);
		ob->set("qi",     2500);
		ob->set("max_jing", 2000);
		ob->set("eff_jing", 2000);
		ob->set("jing",     2000);
		ob->set("max_neili",3000);
		ob->set("neili",3000);
		ob->set("jiali", 120);
	}
	else if(type==2)
	{
//		skl = 150 + random(50);
		ob->set("combat_exp",  maxexp );
		skl=ceil( pow( query("combat_exp")*10.0, 0.333333));
//		ob->set("max_qi", 2500);
//		ob->set("eff_qi", 2500);
//		ob->set("qi",     2500);
		ob->set("max_qi", 2000);
		ob->set("eff_qi", 2000);
		ob->set("qi",     2000);
		ob->set("max_jing", 1500);
		ob->set("eff_jing", 1500);
		ob->set("jing",     1500);
		ob->set("max_neili",2500);
		ob->set("neili",2500);
		ob->set("jiali", 110); 
	}
	else 
	{
//		skl = 100 + random(50);
		ob->set("combat_exp",  (maxexp - random(maxexp)));
		skl=ceil( pow( query("combat_exp")*10.0, 0.333333));
//		ob->set("max_qi", 2000);
//		ob->set("eff_qi", 2000);
//		ob->set("qi",     2000);
		ob->set("max_qi", 1500);
		ob->set("eff_qi", 1500);
		ob->set("qi",     1500);
		ob->set("max_jing", 1000);
		ob->set("eff_jing", 1000);
		ob->set("jing",     1000);
		ob->set("max_neili",2000);
		ob->set("neili",2000);
		ob->set("jiali", 100); 
	}
	skt=random(5);
	if( skt == 0 )
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("hand",skl);
		ob->set_skill("blade", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("yujiamu-quan", skl);
		ob->set_skill("huoyan-dao", skl);
		ob->set_skill("shenkong-xing",skl);
		ob->set_skill("xue-dao",skl);
		ob->set_skill("xiaowuxiang",skl);
		ob->map_skill("force", "xiaowuxiang");
		ob->map_skill("blade", "xue-dao");
		ob->map_skill("cuff", "yujiamu-quan");
		ob->map_skill("strike", "huoyan-dao");
		ob->map_skill("dodge", "shenkong-xing");
		ob->map_skill("parry", "huoyan-dao");
		ob->prepare_skill("cuff", "yujiamu-quan");
		ob->prepare_skill("strike", "huoyan-dao");
		weapon = new( "/clone/weapon/blade");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if( skt == 1 )
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("spear", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("zhusha-zhang", skl);
		ob->set_skill("tiezhang-zhangfa", skl);
		ob->set_skill("shuishangpiao",skl);
		ob->set_skill("tiexue-qiang",skl);
		ob->set_skill("guiyuan-tunafa",skl);
		ob->map_skill("force", "guiyuan-tunafa");
		ob->map_skill("spear", "tiexue-qiang");
		ob->map_skill("strike", "tiezhang-zhangfa");
		ob->map_skill("dodge", "shuishangpiao");
		ob->map_skill("parry", "zhusha-zhang");
		ob->prepare_skill("strike", "tiezhang-zhangfa");
		weapon = new( "/clone/weapon/spear");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if ( skt == 2)
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("claw", skl);
		ob->set_skill("staff", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("huagong-dafa", skl);
		ob->set_skill("sanyin-wugongzhao", skl);
		ob->set_skill("chousui-zhang",skl);
		ob->set_skill("tianshan-zhang",skl);
		ob->set_skill("zhaixinggong",skl);
		ob->map_skill("force", "huagong-dafa");
		ob->map_skill("staff", "tianshan-zhang");
		ob->map_skill("strike", "choushui-zhang");
		ob->map_skill("claw", "sanyin-wugongzhao");
		ob->map_skill("dodge", "zhaixinggong");
		ob->map_skill("parry", "choushui-zhang");
		ob->prepare_skill("strike", "chousui-zhang");
		ob->prepare_skill("claw", "sanyin-wugongzhao");
		weapon = new( "/clone/weapon/staff");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else if ( skt == 3)
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("sword", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("jinshe-zhang", skl);
		ob->set_skill("jinshe-jian", skl);
		ob->set_skill("shuishangpiao",skl);
		ob->set_skill("guiyuan-tunafa",skl);
		ob->map_skill("force", "guiyuan-tunafa");
		ob->map_skill("sword", "jinshe-jian");
		ob->map_skill("strike", "jinshe-zhang");
		ob->map_skill("dodge", "shuishangpiao");
		ob->map_skill("parry", "jinshe-zhang");
		ob->prepare_skill("strike", "jinshe-zhang");
		weapon = new( "/clone/weapon/sword");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	else 
	{
		ob->set_skill("force", skl);
		ob->set_skill("strike", skl);
		ob->set_skill("cuff", skl);
		ob->set_skill("whip", skl);
		ob->set_skill("dodge", skl);
		ob->set_skill("parry", skl);	
		ob->set_skill("xiantian-qigong", skl);
		ob->set_skill("duanyun-bian", skl);
		ob->set_skill("jinyan-gong",skl);
		ob->set_skill("haotian-zhang",skl);
		ob->set_skill("chunyang-quan",skl);
		ob->map_skill("force", "xiantian-qigong");
		ob->map_skill("whip", "duanyun-bian");
		ob->map_skill("strike", "haotian-zhang");
		ob->map_skill("cuff", "chunyang-quan");
		ob->map_skill("dodge", "jinyan-gong");
		ob->map_skill("parry", "chunyang-quan");
		ob->prepare_skill("strike", "haotian-zhang");
		ob->prepare_skill("cuff", "chunyang-quan");
		weapon = new( "/clone/weapon/whip");
		weapon->set("value", 0);
		weapon->move( ob );
		weapon->wield();
	}
	return 1;
}

void die()
{
	object ob,obj,gift;
	int  maxexp;
	int i,j;
	object* ob_list;
	ob=query_temp("last_damage_from");
	maxexp = (int)ob->query_temp("guojx_mis_max");
	ob_list = children("/d/xiangyang/task/mengbing");
	j=sizeof(ob_list);
	for (i=1;i<sizeof(ob_list);i++)
	if (!environment(ob_list[i])) j--;
  if ((int)ob->query_condition("guojx_mis")>=1)
   { 
		if (j<=1)
		{
			tell_room(environment(ob),HIC"\n一直躲在一旁的蒙古奸细见大势已去，旋即也扑了上来。\n"NOR);
			ob->set_temp("guojx_mis_flag",3);
			obj=new(__DIR__"jianxi"); 
			obj->do_copy( maxexp );
			obj->set("title",HIR"奸细"NOR);
			obj->move(environment(ob));
			obj->kill_ob(ob);
			gift=new(__DIR__"mijian");
			gift->set_temp("host",ob->query("id"));
			gift->move(obj);
			obj->call_out("task_over",300,obj,ob);
		}
   }
	message_vision("$N扑在地上挣扎了几下，口中喷出几口"HIR"鲜血"NOR"，死了！\n",this_object());
	destruct(this_object());
	return;
}

void task_over(object obj,object me)
{
	object *team;
	int i=0,count;
	
	team=me->query_team();
	count=sizeof(team);
	tell_room(environment(obj),HIC"蒙古兵挥挥手，示意奸细先走。\n奸细匆匆忙忙的离开了。\n"NOR);
	for(i=0;i<count;i++)
	{
		team[i]->delete_temp("guojx_mis_tcount");
		team[i]->delete_temp("guojx_mis_where");
		team[i]->delete_temp("guojx_mis_flag");
		team[i]->delete_temp("guojx_mis_time");
		team[i]->delete_temp("guojx_mis_max");
		team[i]->clear_condition("guojx_mis");
		tell_object(team[i], HIY"\n奸细离开中原了，你们的任务失败了！\n"NOR);
	}
	destruct(obj);
	return;
}