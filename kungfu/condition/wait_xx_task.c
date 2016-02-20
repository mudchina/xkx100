// Last Modified by Winder on Apr. 25 2001
// wait_xx_task.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	if (duration < 1)
	{
		message_vision(HIW"突然天空中飞下一只白鸽，降在$N的肩头。\n"NOR, me);
		tell_object(me, HIY"这是一封新的飞鸽传书，你又可以要求新的任务了！\n"NOR);		
		return 0;
	}
	me->apply_condition("wait_xx_task", duration - 1);
	return 1;
}

string query_type(object me)
{
	return "job";
}

