// ill_dongshang.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "肢体僵直，看来被冻伤了。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"你觉得肢体末端一阵僵直，看来是被冻伤了！\n" NOR );
		message("vision", me->name() + "的肢体僵直青肿，看来被冻伤了。\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"饥寒交迫冻死在"+environment(me)->query("short")+"了。");
	me->receive_damage("qi", 1,"饥寒交迫冻死在"+environment(me)->query("short")+"了。");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ill_dongshang", duration - 1);

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}
