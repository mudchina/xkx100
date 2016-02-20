// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/heal") &&
  !me->query("can_perform/bahuang-gong/heal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	if( (int)me->query_skill("bahuang-gong", 1) < 20)
		return notify_fail("你的八荒六合唯我独尊功修为还不够。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");
/*
	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail(HIR"你没有受伤，不必运真气疗伤！\n"NOR);
*/
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail(HIR"你已经受伤过重，只怕一运真气便有生命危险！\n"NOR);

	write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
	message("vision", HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR, environment(me), me);

	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(1);

	return 1;
}
int help(object me)
{
	write(WHT"\n八荒六合唯我独尊功之自疗："NOR"\n");
	write(@HELP

	使用功效：
		为自己疗伤

	出手要求：
		八荒六合唯我独尊功20级
		内力50
HELP
	);
	return 1;
}

