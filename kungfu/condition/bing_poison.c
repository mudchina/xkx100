// bing_poison.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me,HIB"突然你感觉四肢麻麻的似乎不大灵便！\n"NOR);
	tell_room(environment(me),HIB+me->name()+"突然全身一颤，两张手掌心已全成黑色，黑气更顺着手臂向上攀升！\n"NOR, ({ me }));     
	me->receive_damage("qi", 25);
	if(userp(me)) me->receive_wound("jing", 20,"中冰晶毒");
	else me->receive_wound("jing", 40,"中冰晶毒");
	if(!me->is_busy()) me->start_busy(2);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("bing_poison", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
