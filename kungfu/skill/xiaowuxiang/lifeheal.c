// lifeheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/lifeheal") &&
  !me->query("can_perform/xiaowuxiang/lifeheal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( !target || !target->is_character() || target == me )
		return notify_fail("你要用真气为谁疗伤？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	if( target->is_busy())
		return notify_fail(target->name()+"现在正忙着呢！\n");

	if( (int)me->query_skill("xiaowuxiang", 1) < 30 )
		return notify_fail("你的小无相功修为不够。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150 )
		return notify_fail("你的真气不够。\n");
/*
	if( (int)target->query("eff_qi") >= (int)target->query("max_qi") )
		return notify_fail( target->name() + "只是累了，没有受伤，不必劳起你的真气疗伤！\n");
*/
	if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
		return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");

	message_combatd( HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR, me, target );

	target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
	target->add("qi", 10 + (int)me->query_skill("force")/3 );
	if( (int)target->query("qi") > (int)target->query("eff_qi") )
		target->set("qi", (int)target->query("eff_qi"));

	me->add("neili", -50);
	me->start_busy(1);
	if ( userp(target)) target->start_busy(2);

	return 1;
}

int help(object me)
{
	write(WHT"\n小无相功之他疗："NOR"\n");
	write(@HELP

	使用功效：
		为他人疗伤

	出手要求：
		小无相功30级
	        内力300
HELP
	);
	return 1;
}

