// ss_poison.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 0;
	if( duration < 1 ) return 0;
	if( !living(me) || me->query_temp("noliving") )
	{
		message("vision", me->name() + "凄惨地哼了一声。\n", environment(me), me);
	}
	else
	{
		tell_object(me, HIB"忽然一股寒流夹着一阵灼热涌上心来，你中的生死符发作了！\n"NOR );
		message("vision", me->name() + "突然倒在地上，双手在身上一阵乱抓。\n", environment(me), me);
	}
	me->receive_wound("qi",30 + random(10),"生死符发作");
	me->receive_wound("jing", 10,"生死符发作");
//	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ss_poison", duration );

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
