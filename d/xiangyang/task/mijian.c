// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"军机密件"NOR, ({ "mi jian"}));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封军机密件，记载着襄阳城守军的兵力部署。\n");
		set("value", 0);
		set("material", "paper");
	}
}
void init()
{    
	add_action("do_xiaohui", "xiaohui");
}
int do_xiaohui(string arg)
{
	int i,exp,pot,count,base_exp,time;
	object ob,me,*team;
	me=this_player();
	ob=this_object();
	if(!arg||arg!="mi jian") return notify_fail("你要销毁什么？\n");
	if(ob->query_temp("host")!= me->query("id") ||
		!me->query_condition("guojx_mis") ||
		!me->query_temp("guojx_mis_tcount"))
		return notify_fail("这件事好像和你没关系吧？\n");
	if (!present("mi jian",me) )
		return notify_fail("你身上没有密件。\n"); 
	message_vision("$N从怀中掏出一只火折点燃了密件。\n"+HIR"只听「轰」的一声，密件在火中慢慢化为灰烬。\n"NOR, me);
	count=me->query_temp("guojx_mis_tcount");
	if (count<2) count=2;	
	base_exp=300;
	time = me->query_temp("guojx_mis_time",time);
	team=me->query_team();
	count=sizeof(team);
	for(i=0;i<count;i++)
	{
		if(team[i]!=0)
		{
			if (team[i]->query_condition("guojx_mis"))
			{
				exp=base_exp*time + random(300);
				pot=exp/3+random(100);
        log_file("mission/guo_team",sprintf("%-20s 做阻截奸细任务获得 %-5s 经验 %-5s 潜能",team[i]->query("name")+"("+team[i]->query("id")+")",exp,pot));
				team[i]->add("potential",pot);
				team[i]->add("combat_exp",exp);
	team[i]->set_temp("prize_reason","狙击");
	team[i]->set_temp("can_give_prize",1);
	team[i]->set_temp("prize_exp",exp);
	team[i]->set_temp("prize_pot",pot);
				tell_object(team[i],HIW"你被奖励了：" + 
				chinese_number(exp) + "点实战经验，" +
				chinese_number(pot) + "点潜能。\n"+ NOR);
				team[i]->delete_temp("guojx_mis_tcount");
				team[i]->delete_temp("guojx_mis_where");
				team[i]->delete_temp("guojx_mis_flag");
				team[i]->delete_temp("guojx_mis_time");
				team[i]->delete_temp("guojx_mis_max");
				team[i]->clear_condition("guojx_mis");
			}
		} 
	}
	destruct(this_object());
	return 1;
}

