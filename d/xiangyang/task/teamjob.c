// Last Modified by Sir 2003.11.
// teamjob.c
#include <ansi.h>
mixed address = ({
	({
	"朱雀外门","青龙外门","白虎外门","玄武外门","天安门","玄妙观","灵隐寺",
	"泉州南门","灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",
	"衡阳西街","喜州城","葛鲁城","伊犁城","山海关","老龙头","长白天池",
	"天山脚下","丽春院","涌泉寺","五老峰","紫金城","松风观","终南山脚",
	"抱子岩","升仙坊","嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
	}),
});

int ask_jianxi()
{
	object ob,guo;
	object *team;
	int i=0,count=0,time,minexp,maxexp,flag;
	string where;
	ob=this_player();
	guo=this_object();

	if(ob->query("combat_exp")<500000) 
	{
		tell_object(ob,"郭靖对你笑道：“你的武功太差了，等练强了再来吧。”\n");
		return 1;
	}
	if(guo->query("jxjob_start"))
	{
		tell_object(ob,"郭靖对你笑道：“已经有英雄前去阻截奸细了，你看去帮帮忙如何？”\n");
		return 1;
	}
	team=ob->query_team();
	count=sizeof(team);
	if(count<=1)
	{
		tell_object(ob,"郭靖对你笑道：“就阁下一个人恐怕难担此重任吧？”\n");
		return 1;
	}
	if(count>=5) 
	{
		tell_object(ob,"郭靖对你说道：“此事事关重大，不宜张扬！”\n");
		return 1;
	}
	minexp=team[0]->query("combat_exp");
	maxexp=minexp;
      
	for(i=1;i<count;i++)
	{
		if(team[i]!=0)
		{
			if(team[i]->query("combat_exp")<minexp)
				minexp=team[i]->query("combat_exp");
			if(team[i]->query("combat_exp")>maxexp)
				maxexp=team[i]->query("combat_exp");
			if((int)team[i]->query_condition("guojx_mis"))
				flag = 1;
		}
	}
	if ((maxexp-minexp)>2000000)
	{
		tell_object(ob,"郭靖对你说道：“诸位武功相差太过悬殊，恐难完成所托重任！”\n");
		return 1;
	}
	if (flag == 1)
	{
		tell_object(ob,"郭靖对你说道：“你的队伍中有人还没完成任务呢！”\n");
		return 1;
	}
	// 成功检测
	where=address[0][random(sizeof(address[0]))];
	time = 3 + random(3);
	for(i=0;i<count;i++)
	{
		team[i]->set_temp("guojx_mis_tcount",count);
		team[i]->set_temp("guojx_mis_where",where);
		team[i]->set_temp("guojx_mis_flag",1);
		team[i]->set_temp("guojx_mis_time",time);
		team[i]->set_temp("guojx_mis_max",maxexp);
		team[i]->apply_condition("guojx_mis",60);
	}
	guo->set("jxjob_start",1);
	call_out("guojxjob",30,ob,maxexp,time);
//	call_out("new_start_jxjob",1200,guo);
	call_out("new_start_jxjob",300,guo);
	tell_object(ob,"郭靖对你说道：“我刚得到消息，有一名蒙古奸细偷盗了襄阳
城防的机密文件。你们赶快去"+where+"设防阻截，抢到文件后就
地销毁(xiaohui)。蒙古人肯定会派兵接应他，多加小心。”\n");
message("channel:sys", HIR"【阻截奸细】"+ob->query("name")+"申请阻截"+ob->query_temp("guojx_mis_where")+"奸细任务。\n"NOR, users());
	return 1;
}

int new_start_jxjob()
{ 
   this_object()->delete("jxjob_start", 1);
}


void guojxjob(object ob,int maxexp,int time)
{
	object *team,obj,gift;
	int i=0,j=0,count,knum,lvl,flag = 999;
	
	team=ob->query_team();
	count=sizeof(team);
	for(i=0;i<count;i++)
	{
		if ((int)team[i]->query_condition("guojx_mis"))
		{
			if ( team[i]->query_temp("guojx_mis_flag") == 1 )
				flag = 0;
			else if( flag != 0 && team[i]->query_temp("guojx_mis_flag") == 2 )
				flag = 1;
		}
	}
	if ( flag == 0 )
	{
		ob->remove_call_out("guojxjob");
		call_out("guojxjob",10,ob,maxexp,time);
		return;
	}
	if(environment(ob)->query("short")==ob->query_temp("guojx_mis_where")&& (int)ob->query_condition("guojx_mis"))
	{
		message_vision(HIY "突然间从路旁闪出一队蒙古鞑子，队伍中夹杂着一个蒙面人，行色匆匆，似乎急着要离开！\n"NOR, ob);
		message_vision(HIY "$N冲着蒙面人大喝一声：大胆奸细，偷了襄阳城防图，还想跑么？\n"NOR, ob);
		message_vision(HIY "蒙面人一看事情败露，狂笑不已：就凭你们几个也想挡住我的去路？\n"NOR, ob);
		for(j=0;j<time;j++)
		{
		for(i=0;i<count;i++)
		{
			lvl = random(20);
			obj=new(__DIR__"mengbing");
			if (lvl >16 )
			{   
				obj->do_copy( maxexp,3);
				obj->set("title",HIY"蒙古千夫长"NOR);
			}
			else if (lvl > 8 )
			{ 
				obj->do_copy( maxexp,2);
				obj->set("title",HIY"蒙古百夫长"NOR);
			}
			else 
			{
				obj->do_copy( maxexp,1);
				obj->set("title",HIY"蒙古兵士"NOR);
			}
			knum = random(count);
			if (environment(team[knum])->query("short")==ob->query_temp("guojx_mis_where"))
			{     
				obj->move(environment(team[knum]));
				obj->kill_ob(team[knum]);
			}
			else
			{	
				obj->move(environment(ob));
				obj->kill_ob(ob);
			}
		}
		}
	}
	else
	{
		for(i=0;i<count;i++)
		{
			team[i]->delete_temp("guojx_mis_tcount");
			team[i]->delete_temp("guojx_mis_where");
			team[i]->delete_temp("guojx_mis_flag");
			team[i]->delete_temp("guojx_mis_time");
			team[i]->delete_temp("guojx_mis_max");
			team[i]->clear_condition("guojx_mis");
			tell_object(team[i], HIY "\n奸细偷偷溜出了中原，你们的任务失败了！\n" NOR);
		}
	} 
	return;
}
