// ill_shanghan.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if (me->is_ghost()) return 1;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"打了个冷战，头昏沉沉的，好象是得伤寒病了！\n"NOR );
		message("vision", me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n", environment(me), me);
	}
	me->receive_wound("qi", 1,"伤寒过重，无人医治病死了。");
	me->receive_damage("qi", 1,"伤寒过重，无人医治病死了。");
	me->apply_condition("ill_shanghan", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "ill";
}
