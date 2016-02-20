// huaiyun.c
// by angle

#include <ansi.h>
#include <condition.h>
int shengle(object me);
int birth1(object me,object obj);
void birth2(object me,object obj);
object create_baby(object me,object obj);

inherit F_CLEAN_UP;


int update_condition(object me, int duration)
{// 320个heart_beat一个月  
	if ( me->is_fighting() && duration < 2230 && duration > 0 ){
		tell_object(me, HIR "你突然觉得有些体力不支，打起架来特别费力。\n" NOR );
    if (me->query("neili")>200) 
     me->add("neili",-200);
    else
     me->set("neili",0);
	}
	else if ( duration == 2720 || duration == 2700){
		tell_object(me, HIB "你突然感到一阵的恶心，忍不住到路边吐了一会儿，总算是好些了。\n" NOR );
	}
	else if (duration ==2560 || duration == 2565 ){
			tell_object(me, HIB "你突然感到一阵的恶心，连忙捂住嘴，差点又忍不住吐了出来。\n难道上次他。。。。。\n" NOR );
	}
	else if (duration >=2230 &&  duration <2560 ){
		if (duration%10==1)
			tell_object(me, HIB "你觉得身体有点不舒服，常常有种恶心的感觉。\n" NOR );
	}
	else if (duration >=1300 && duration <2230 ){
		if (random(20)==1)
	  {
	  	if (me->query("food")>5) me->add("food",-5);
	  	if (me->query("water")>5) me->add("water",-5);
				tell_object(me, HIY "你觉得肚子很饿，想吃点什么东西。\n" NOR );
		}else if(random(20)==1)
		{
			if (me->query("jing")>10) me->add("jing",-10);
			if (me->query("qi")>10) me->add("qi",-10);
		  tell_object(me, HIY "你感到有些疲惫，腰酸背痛，没什么力气。\n" NOR );
			}
	}
	else if (duration > 80 && duration < 1300 ){ if (random(50)==1)
			tell_object(me, HIB "肚子里的小家伙不安分地踢了你一脚。\n" NOR );
	}
	else if (duration <= 80 && duration >0){
			if (!environment(me)->query("if_bed"))
			tell_object(me, HIR "你感到肚子翻江倒海般地疼了起来。好像是快要生了，快把孩子的父亲叫来，回家躺着吧。\n" NOR );
			else 	if (!present(me->query("baby/father"),environment(me)))
			tell_object(me, HIY "你躺在床上感觉好多了，赶快把孩子的父亲叫过来吧。\n" NOR );
      else if (random(5)==1)
      call_out("shengle",5,me);
			else 
			tell_object(me, HIY "你躺在床上感觉好多了，回家了就什么也别想了，静静地等待孩子出世吧。\n" NOR );
	}
	else if (duration == 0 ){
			tell_object(me, RED "你只觉腹肚疼痛难忍，浑身大汗淋漓。好难受啊，让我死了吧。。。\n" NOR );
		  call_out("shengle",5,me);
  }
	if (duration<2230)
	if (!me->query_temp("apply/attack") || me->query_temp("apply/attack")>=0)
		me->add_temp("apply/attack",-100000);//降低攻击
	me->apply_condition("huaiyun", duration - 1);
	return 1;
}
int shengle(object me)
{
	object obj= find_player(me->query("baby/father"));
	if (me->query_temp("apply/attack")<-95000)
	me->add_temp("apply/attack",100000);//恢复攻击力
	if( !environment(me)->query("if_bed") )
	{
		message_vision(HIY "\n$N似乎觉得腹中一阵巨痛，大叫一声，由于这里的环境实在是太恶劣了，\n$N的孩子流产了，好可怜啊！\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
		me->unconcious();
	 } 
	 else if (!obj || !userp(obj) || !present(obj, environment(me)) )
	 {		
		message_vision(HIY "\n$N似乎觉得腹中一阵巨痛，大叫一声，由于关键时刻孩子的父亲没有守侯在你身边，\n$N的孩子流产了，好可怜啊！\n"NOR, me);
		me->set("qi",1);
		me->set("jing",1);
		me->set("neili", me->query("neili")/2);
		me->unconcious();
	 } 
	 else
	 {
		me->set_temp("is_bearing",1);
		me->start(100);
		obj->start(100);
		message_vision(HIY "\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n" NOR, me,obj);
		call_out("birth1",15,me,obj);
	 }
   me->clear_condition("huaiyun");
	 return 1;
}

int birth1(object me,object obj)
{  
	 message_vision(HIY "\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n"+
		 "\n婴儿已经探出了头．．．\n"NOR,me,obj);
	 call_out("birth2",15,me,obj);
	 return 1;
}

void birth2(object me,object obj)
{
	int twins=0;
	object baby1,baby2;
	me->start_busy(1);
	obj->start_busy(1);
	me->set("neili",0);
	me->set("qi",0);
	me->set("jing",0);
	if (!baby1=create_baby(me,obj)) 
		return;
 if (random(30)==1)
 {	
	me->set("baby/gender",random(2)+1);
	if (!baby1=create_baby(me,obj)) 
		return;
 	tell_object(me,"恭喜恭喜。两位的运气真好，竟然是一对双胞胎。\n");
	tell_object(obj,"恭喜恭喜。两位的运气真好，竟然是一对双胞胎。\n");
	twins=1;
}	
	message_vision(HIY "\n「哇」．．．，婴儿出世了！\n"+
		"\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n"NOR, me);
	me->delete_temp("is_bearing");
	me->delete("baby/father");
	me->delete("baby/gender");
	me->save();
	obj->save();
//this needs to be put at the last since
//can only move the baby after it's parameters are set.
	if(!baby1->move(environment(me)))
	baby1->move(environment(environment(me)));
	if(twins && !baby2->move(environment(me)))
	baby2->move(environment(environment(me)));
	return;
}

object create_baby(object me,object obj)
{
	object baby;
	int number;
	seteuid(getuid());
	if (!baby = new("/d/taohuacun/npc/baby"))
		{
			tell_object(me,"系统出错，请通知巫师解决。\n");
			return 0;
		}
	baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。\n");
	me->add("child",1);
	obj->add("child",1);
//	if (random(100)<50)
	if (me->query("baby/gender")==1)
	{		
		baby->set("gender","男性");
		baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby" ,obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
		me->set("child_"+me->query("child")+"/id",({baby->query("id"),"baby",obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
		//set(child_1/id,({xiao myname,baby,myname1.wfname1}))
		obj->set("child_"+obj->query("child")+"/id",({baby->query("id"),"baby",obj->query("id")+obj->query("child")+"."+me->query("id")+me->query("child")}));
	}	else if (me->query("baby/gender")==2)
	{
		baby->set("gender","女性");
		baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
		me->set("child_"+me->query("child")+"/id",({baby->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
		obj->set("child_"+obj->query("child")+"/id",({baby->query("id"),"baby",me->query("id")+me->query("child")+"."+obj->query("id")+obj->query("child")}));
	}
	else //wrong data
	{
	message_vision(HIR "$N终因体力不支流产了，$N惨叫一声晕了过去。\n"NOR, me);
	me->unconcious();
	return 0;
		}
	baby->set("parents",({me->query("id"),obj->query("id")}));
	baby->set("saveid",me->query("id")+me->query("child")+obj->query("id")+obj->query("child"));
	number = me->query("child");
	me->set("child_"+number+"/long",baby->query("long"));
	me->set("child_"+number+"/name",baby->query("name"));
	me->set("child_"+number+"/parents",baby->query("parents"));
	me->set("child_"+number+"/gender",baby->query("gender"));
	me->set("child_"+number+"/saveid",baby->query("saveid"));
	number = obj->query("child");
	obj->set("child_"+number+"/long",baby->query("long"));
	obj->set("child_"+number+"/name",baby->query("name"));
	obj->set("child_"+number+"/parents",baby->query("parents"));
	obj->set("child_"+number+"/gender",baby->query("gender"));
	obj->set("child_"+number+"/saveid",baby->query("saveid"));
	baby->move(environment(me));
	baby->save();
	return baby;
}
