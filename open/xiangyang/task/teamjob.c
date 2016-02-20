// Last Modified by winder on Apr. 25 2001
// teamjob.c
#include <ansi.h>
mixed names = ({
	({
	"朱雀外门","青龙外门","白虎外门","玄武外门","天安门","玄妙观","灵隐寺",
	"泉州南门","灵州南门","诸葛亮殿","烟雨楼","南阳城","佛山南门",
	"衡阳西街","喜州城","葛鲁城","伊犁城","山海关","老龙头","长白天池",
	"天山脚下","丽春院","涌泉寺","五老峰","紫金城","松风观","终南山脚",
	"抱子岩","升仙坊","嘉应门","玄妙观","峻极禅院","侠义厅","萧家桥", 
	}),
	({
	"郭芙","武三通","朱子柳","静玄师太","静照师太","宋远桥","莫声谷",
	"陆乘风","韩宝驹","黄药师","余沧海","殷野王","胡青牛","尹志平","小龙女",
	"刘乘风","欧阳锋","九翼道人","阿紫","玉磬子","玉音子","岳夫人","岳不群",
	"令狐冲","玄苦大师","清善比丘","独臂神尼","庄夫人","双儿","吴六奇",
	"木婉清","萧远山","李沅芷","向问天","曲洋","黑白子","程瑶迦","沐剑屏",
	"天柏道人","本尘","本观","天山童姥","韦一笑","谢逊","澄坚","陆乘风",
	"张翠山","宋青书","玄贞道长","石破天","苏星河","逍遥子","朱丹臣",
	"简长老","封不平",
	}),
});

string ask_jianxi()
{
	object guo,ob;
	object *team;
	int i=0,count=0,minexp,maxexp;
	string where;
	guo =this_object();
	ob=this_player();

	if (guo->query_condition("zzz_busy")) return "我没有收到任何消息。";
	if(ob->query("combat_exp")<500000) return "你的功夫太差了。";
	team=ob->query_team();
	count=sizeof(team);
//	write("\n"+sprintf("%d",count));
	if(count<=1) return "就你一个人？";    // 不能单独做
	if(count>=5) return "此事不宜张扬。";  // 不能超过五人一起做
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
		}
	}
	if ((maxexp-minexp)>800000)
		return "你们的武功相差太悬殊。";// 同伙武功差距不能太大
	// 成功检测
	where=names[0][random(40)];
	guo->apply_condition("zzz_busy",30);
	ob->set_temp("team_count",count);
	ob->apply_condition("zzz_busy",60);
	for(i=0;i<count;i++)
//		team[i]->set_temp("zzz_job_zhuji",1);
		team[i]->apply_condition("zzz_busy",60);
	for(i=100;i*i*i/10<=maxexp;i++);
	call_out("job",60,ob,where,i,count+2);
//	message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路？\n"NOR,obj);
	return "我刚得到消息，有一名蒙古奸细偷盗了襄阳城防的机密文件。
          你们赶快去"+where+"设防阻截，抢到文件后就地销毁(xiaohui)。
          蒙古人肯定会派兵接应他，多加小心。"; 
}

void job(object ob,string where,int maxpot,int ckiller)
{
	object *team,obj,obj1,gift;
	int i=0;
//	team=ob->query_team();
//	for(i=0;i<sizeof(team);i++)
	if(environment(ob)->query("short")==where &&
		ob->query_condition("zzz_busy"))
	{
		if (ckiller>0)
		{
			if (random(20)>16)
			{
				obj=new(__DIR__"mengbing");   
				obj->do_copy(ob,maxpot,3);
				obj->set("title",HIY"蒙古千夫长"NOR);     
				obj->move(environment(ob));
				obj->kill_ob(ob);
			}
			else 
			{
				obj=new(__DIR__"mengbing"); 
				obj->do_copy(ob,maxpot,1);
				obj->set("title",HIY"蒙古百夫长"NOR);
				obj->move(environment(ob));
				obj->kill_ob(ob);
				obj1=new(__DIR__"mengbing");
				if (random(20)>10)
				{
					obj1->do_copy(ob,maxpot,2);
					obj1->set("title",HIY"蒙古百夫长"NOR);
				}
				else obj1->do_copy(ob,maxpot,1);
				obj1->move(environment(ob));
				obj1->kill_ob(ob);
			}  
			call_out("job",120,ob,where,maxpot,ckiller-1);
		}
		else 
		{
			if (present("menggu dahan",environment(ob)))
			{
// present menggu dahan, then mission failed
				tell_room(environment(ob),HIC"蒙古兵挥挥手，示意奸细先走。\n奸细匆匆忙忙的离开了。\n"NOR);
				tell_object(ob, HIY"\n奸细离开中原了，你任务失败！\n"NOR);
			}
			else
			{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIR"奸细"NOR);
				obj->move(environment(ob));
				message_vision(HIY "$N狂笑不已：就凭你们几个也想挡住我的去路？\n"NOR, obj);
				obj->kill_ob(ob);
				gift=new(__DIR__"mijian");
				gift->set_temp("host",ob->query("id"));
				gift->move(obj);
			}
		}
	}
	else
	tell_object(ob, HIY "\n奸细偷偷溜出了中原，你任务失败！\n" NOR); 
	return;
}
//make killer
