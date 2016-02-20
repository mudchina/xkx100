// jingheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
/*
	if ((!target) || target->query("id")!=me->query("id"))
		return notify_fail("你要用真气为谁护精？\n");
*/
  if ( userp(me) && !wizardp(me) && 
  !me->query("can_perform/shenzhao-jing/jingheal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (!target) target = me;

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功护精！\n");

	if( (int)me->query_skill("shenzhao-jing",1) < 50 )
		return notify_fail("你的神照经内功修为不够。\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	if( target->is_busy())
		return notify_fail(target->name()+"现在正忙着呢！\n");

	if( (int)me->query("max_neili") < 200)
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if( (int)target->query("eff_jing") >= (int)target->query("max_jing"))
		return notify_fail("只有精气受损才需要护精。\n");

	if( (int)target->query("eff_jing") < (int)target->query("max_jing") / 5)
		return notify_fail("精气受损过重，经受不起真气震荡！\n");

  if ( me != target)
	message_combatd( HIC "$N坐了下来运起神照经内功，将左手掌贴在$n后背命门，右掌捂住$n丹田，缓缓地将运转真气....\n\n"HIY "过了不久，$n额头上冒出豆大的汗珠，脸上的疲惫模样也减轻多了。\n" NOR, me, target);
  else 
 	message_combatd( HIC "$N坐了下来运起神照经内功，将左手掌贴在后背命门，右掌捂住丹田，缓缓地将运转真气....\n\n"HIY "过了不久，$N额头上冒出豆大的汗珠，脸上的疲惫模样也减轻多了。\n" NOR, me);

  
	target->receive_curing("jing", 10 + (int)me->query_skill("force")/2 );
	if( (int)target->query("jing") > (int)target->query("eff_jing") )
		target->set("jing", (int)me->query("eff_jing"));

	me->add("neili", -50);
	me->start_busy(3);
	target->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n神照经之疗精"NOR"\n");
	write(@HELP

	使用功效：
		为自己或他人护精

	出手要求：
		神照经50级
		内力200
HELP
	);
	return 1;
}

