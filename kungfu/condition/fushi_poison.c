// Last Modified by winder on May. 15 2001
// fushi_poison.c 府尸毒

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{         
  if (me->is_ghost()) return 1;
	tell_object(me,HIB"你突然觉得一股恶臭从腹中升起，不禁大呕起来！\n"NOR);
	tell_room(environment(me),HIB + me->name()+"脸上浮着一层黑气，脚步蹒跚，突然吐出一堆秽物！\n" NOR, ({ me }));             
	me->receive_wound("jing", 25,"腐尸毒发作");
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("fushi_poison", duration - 1);   
	if( duration < 1 ) return 0;   
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}
