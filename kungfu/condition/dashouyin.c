// dashouyin.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <condition.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage, p;
	string msg;
  if (me->is_ghost()) return 1;
	damage = me->query_condition("dashouyin") +2;
	damage *= me->query_con();
	
	tell_object(me,"突然你感觉胸口疼痛异常，刚才被大手印拍中的肋骨处好象要裂开了似的，鲜血也从口中喷了出来！\n");
	tell_room(environment(me),HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
	me->receive_damage("qi", damage,"大手印劲力发作");
	me->receive_wound("qi", damage/2,"大手印劲力发作");
	p = (int)me->query("qi")*100/(int)me->query("max_qi");
	msg = "( $N"+eff_status_msg(p)+" )\n";
	if( living(me) && !me->query_temp("noliving")) message_vision(msg, me);
	if ((int)me->query("eff_jing")<0 || (int)me->query("eff_qi")<0) return 0;
	me->apply_condition("dashouyin", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}

string query_type(object me)
{
	return "hurt";
}
