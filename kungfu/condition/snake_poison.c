// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 0;
	tell_object(me, HIG"你感到伤口一阵阵麻痒，恨不得用手使劲挠。你中的蛇毒发作了！\n" NOR );
	me->receive_wound("jing", 10,"蛇毒发作");
	me->receive_damage("qi", 10,"蛇毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("snake_poison", duration - 1);
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
