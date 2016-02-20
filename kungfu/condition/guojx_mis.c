//guojx_mis.c  郭奸细任务

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object* ob_list;
	int i;
	if (duration < 1)
	{
	ob_list = children("/d/xiangyang/task/mengbing");
    for(i=0; i<sizeof(ob_list); i++) 
	{	
		if(environment(ob_list[i]))
		{
			message_vision("$N哈哈大笑道：襄阳守军的城防图总算到手了，撤呼！\n",ob_list[i]);	
			destruct(ob_list[i]);
        }
	}
	ob_list = children("/d/xiangyang/task/jianxi");
    for(i=0; i<sizeof(ob_list); i++) 
	{	
		if(environment(ob_list[i]))
		{
			message_vision("$N哈哈大笑道：襄阳守军的城防图总算送出去了，大功告成！\n",ob_list[i]);
			destruct(ob_list[i]);
        }
	}
//	if (duration < 1)
//	{
		tell_object(me, HIY "你的动作太慢，任务被取消了。\n" NOR);
		me->delete_temp("guojx_mis_where");
		me->delete_temp("guojx_mis_tcount");
		me->delete_temp("guojx_mis_flag");
		me->delete_temp("guojx_mis_time");
		me->delete_temp("guojx_mis_max");
		me->clear_condition("guojx_mis");
		return 0;
	}
	if (!duration) return 0;
	
	if (me->query_temp("guojx_mis_flag") == 1 )
	{							
		if( environment(me)->query("short") == me->query_temp("guojx_mis_where"))
				me->set_temp("guojx_mis_flag",2);
	}
	me->apply_condition("guojx_mis", duration - 1 );
	return 1;
}

string query_type(object me)
{
	return "job";
}
