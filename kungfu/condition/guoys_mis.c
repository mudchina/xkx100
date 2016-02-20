// guoys_mis.c  by Sir 2003.11.13
//郭靖保护义士任务

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	object *obs;
	int i;
	
	
	if (duration < 1)
	{
		tell_object(me, HIY "你的动作太慢，任务被取消了。\n" NOR);

		me->delete_temp("guoys_mis_target");
		me->delete_temp("guoys_mis_given");
		me->delete_temp("guoys_mis_flag");
		me->clear_condition("guoys_mis");
		return 0;
	}
	if (!duration) return 0;
	
	if (me->query_temp("guoys_mis_flag") == 1 )
	{							
		obs = all_inventory(environment(me));
		
		for(i=0; i<sizeof(obs); i++)
		{
			if( !living(obs[i])||userp(obs[i])||obs[i]==me ) continue;
			if(obs[i]->query("name")==me->query_temp("guoys_mis_target"))
			{
				me->set_temp("guoys_mis_flag",2);
			}
		}
	}
	me->apply_condition("guoys_mis", duration - 1 );
	return 1;
}

string query_type(object me)
{
	return "job";
}

