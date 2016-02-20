// flower_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if(me->query_temp("nopoison")) return 0;
	tell_object(me, HIG "你中的" HIR "断肠花毒" HIG "发作了！\n" NOR );
	me->receive_wound("jing", 20,"断肠花毒发作");
	me->receive_damage("qi", 10,"断肠花毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("flower_poison", duration - random(5));
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
