// wakeup.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/wakeup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if ( !target || !target->is_character() )
		return notify_fail("你要用真气救醒谁？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功救人！\n");

	if(target == me)
		return notify_fail("你不能为自己救醒自己！\n");

	if(!target->query_temp("noliving/unconcious") )
		return notify_fail("你只能救醒昏迷不醒的人！\n");

	if(!userp(target))
		return notify_fail("你只能救醒玩家！\n");

	if( (int)me->query_skill("shenzhao-jing", 1) < 100 )
		return notify_fail("你的神照经修为不够。\n");

	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");

	message_combatd(HIY"$N坐了下来运起神照经内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n过了不久，$n慢慢的苏醒过来。\n" NOR, me, target );

//	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
//	target->add("qi", 10 + (int)me->query_skill("force")/3 );
//	if( (int)target->query("qi") > (int)target->query("eff_qi") )
//		target->set("qi", (int)target->query("eff_qi"));

	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	me->add("neili", -150);
	me->set("jiali", 0);
	me->start_busy(5);
	target->start_busy(5);
	return 1;
}
int help(object me)
{
	write(WHT"\n神照经之唤醒"NOR"\n");
	write(@HELP

	使用功效：
		唤醒昏迷中的他人

	出手要求：
		神照经100级
		内力1000
HELP
	);
	return 1;
}

