// Last Modified by winder on Nov. 15 2000
// gb_songxin.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	int time;
	time = me->query_temp("songxin_time");
        me->set("no_get");

	if (duration < 1)
	{
		if (me->query_temp("gb_songxin"))
		{
			tell_object(me, HIY "你时间已过，任务失效！\n" NOR);
		}
		me->delete_temp("gb_songxin");
		me->delete_temp("songxin_name");
		me->delete_temp("songxin_zuji");
		me->delete_temp("songxin_target_name");
		me->delete_temp("letter_steal");
		me->delete_temp("zuji",1);
//		me->delete_temp("wait");
		me->set_temp("gb_songxin_late",1);
   		me->clear_condition("gb_songxin");
//this is dest letter
		if(present("secret letter", me))
			destruct(present("secret letter", me));
		return 0;
	}
	if (!duration) return 0;
/*    
	if (random(10)>3)
	{
		if (me->query("tili")<80)
		{
			tell_object(me, RED "你这样急行送信，消耗太多精力，不由想停下来歇一下！\n" NOR);
			me->set_temp("wait",1);
			me->start_busy(1);
		}
		else
		{
			me->add("tili", -50+random(50));
			me->delete_temp("wait");
		}
	} 
*/
//减少被盗的机率
	if(duration > time/7 && present("secret letter", me) &&
		!me->query_temp("wait") && duration < time &&
		!me->query_temp("songxin_zuji",1)&&random(10)>7 &&
		(interactive(me))&&!environment(me)->query("no_fight") &&
		me->query("disable_type") != " <昏迷不醒>")
	{
		tell_object(me, HIY "你觉的有些不妙，似乎被人跟踪上了！\n" NOR);
		me->start_busy(1);
		call_out("zuji", 0, me);    
	}
	me->apply_condition("gb_songxin", duration - 1);
	return 1;
}

void zuji(object me)
{
	object obj; 
	if (present("secret letter", me)) 
	{
		tell_object(me,"你隐约感觉到有人围了过来。。!!! \n");
		if (random(10)>9)
		{
//this is killer kill npc
			tell_object(me, RED "糟糕！有人要抢信!\n" NOR);

			obj = new("/kungfu/class/gaibang/npc/npc1");
			obj->set("target", me);
			obj->move(environment(me));
			me->set_temp("songxin_zuji",1);

			if (me->query("combat_exp")>300000)
			{
				call_out("killer_clone", 1, me);    
			}
		}
		else
		{
//this is stealer steal letter
			obj = present("secret letter", me);
			destruct(obj);
			tell_object(me,RED"你紧张起来，不由一摸衣袋，不好！信被偷了!\n"NOR);
			me->set_temp("songxin_zuji",1);
			obj = new("/kungfu/class/gaibang/npc/snpc1");
			obj->set("target", me);
			obj->move(environment(me));
  
			if (me->query("combat_exp")>300000)
			{
				call_out("stealer_clone", 1, me);    
			}
		}
	me->delete_temp("gb_songxin");
	me->delete_temp("songxin_name");
	me->delete_temp("songxin_zuji");
	me->delete_temp("songxin_target_name");
	me->delete_temp("letter_steal");
	me->delete_temp("zuji",1);
//	me->delete_temp("wait");
	me->set_temp("gb_songxin_late",1);
   	me->clear_condition("gb_songxin");
	}
	else
	{
		tell_object(me,"信已送出，你庆幸的躲过了一次追杀!\n");
	}   
    return;
}

void killer_clone(object me)
{
	object obj;

	tell_object(me,"糟糕，又冲上来了个人。。!!! \n");
	obj = new("/kungfu/class/gaibang/npc/npc2");
	obj->set("target", me);
	obj->move(environment(me));
	return;
}

void stealer_clone(object me)
{
	object obj;

	tell_object(me,"糟糕，又冲上来了个人。。!!! \n");
	obj = new("/kungfu/class/gaibang/npc/snpc2");
	obj->set("target", me);
	obj->move(environment(me));
	return;
 }

string query_type(object me)
{
	return "job";
}
