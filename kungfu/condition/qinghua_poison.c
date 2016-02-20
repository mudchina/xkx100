// Last Modified by winder on May. 15 2001
// qinghua_poison.c 情花毒
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
  if (me->is_ghost()) return 1;
	tell_object(me, HIM"你的手指上刺损处突然剧痛，伤口微细，痛楚竟然厉害之极，宛如胸\n口蓦地给人用大铁锤猛击一下，你忍不住「啊」的一声叫了出来，忙\n将手指放在口中吮吸。\n" NOR );
	tell_room(environment(me), MAG+ me->name()+"全身犹似为千万只黄蜂同时螯咬，四肢百骸，剧痛难当，忍不住大声号叫。\n" NOR, ({ me }));
	me->receive_damage("qi", 15,"中情花毒");
	me->receive_wound("jing", 15,"中情花毒");
	if(!me->is_busy()) me->start_busy(2); 
		me->apply_condition("qinghua_poison", duration - 1);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
