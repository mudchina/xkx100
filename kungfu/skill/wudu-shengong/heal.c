// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/heal") &&
  !me->query("can_perform/wudu-shengong/heal") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	if( (int)me->query_skill("wudu-shengong", 1) < 30)
		return notify_fail("你的五毒神功修为还不够。\n");

	if( (int)me->query("neili") < 50 )
		return notify_fail("你的真气不够。\n");
/*
	if( (int)me->query("eff_qi") >= (int)me->query("max_qi") )
		return notify_fail(HIR"你没有受伤，不必运真气疗伤！\n"NOR);
*/
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 3 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n
");

	write( HIW "你全身放松，五毒神功流转全身。\n" NOR);
	message("vision", HIW + me->name() + "面颊现出一片潮红，额头上沁出细细的汗珠。\n" NOR, environment(me), me);
	me->set_temp("nopoison", 1);
	me->clear_condition("snake_poison");
	me->clear_condition("wugong_poison");
	me->clear_condition("xiezi_poison");
	me->clear_condition("zhizhu_poison");
	me->clear_condition("chanchu_poison");
	me->clear_condition("scorpion_poison");
	me->clear_condition("ice_poison",0);
	write( HIW "你轻轻呼出一口气，将真气收归丹田，感觉精神好多了。\n" NOR);
	me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
	me->add("neili", -50);
	me->set("jiali", 0);
	me->start_busy(1);
	return 1;
}
int help(object me)
{
	write(WHT"\n五毒神功之自疗："NOR"\n");
	write(@HELP

	使用功效：
		为自己疗伤
		解除本门之毒

	出手要求：
		五毒神功20级
		内力50
HELP
	);
	return 1;
}

