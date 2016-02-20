// /kungfu/condition/ice_sting.c
#include <ansi.h>

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	if(me->query_temp("nopoison")) return 0;
	tell_object(me, HIB "你中的" HIC "冰魄银针毒" HIB "发作了！\n" NOR );
	me->receive_wound("jing", 10,"冰魄银针毒发作");
	me->receive_damage("qi", 10,"冰魄银针毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("ice_sting", duration - random(5));
	if( duration < 1 ) return 0;
	return 1;
}

string query_type(object me)
{
	return "poison";
}
