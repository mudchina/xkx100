// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	me->receive_wound("qi", 20,"火玫瑰毒发作");
	me->receive_damage("qi", 10,"火玫瑰毒发作");
	me->apply_condition("rose_poison", duration - 1);
	tell_object(me, HIG "你中的" HIR "火玫瑰毒" HIG "发作了！\n" NOR );
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
