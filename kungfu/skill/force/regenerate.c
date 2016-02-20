// regenerate.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
//inherit SSERVER;

int exert(object me, object target)
{
	int n, j;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的精气。\n");

	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够。\n");

	j = (int)me->query("eff_jing") - (int)me->query("jing");
	if (j < 10)
		return notify_fail("你现在气力充沛。\n");
	n = 100 * j / me->query_skill("force");
	if (n < 20)
		n = 20;
	if ((int)me->query("neili") < n) {
		j = j * (int)me->query("neili") / n;
		n = (int)me->query("neili");
	}

	me->add("neili", -n);
	me->receive_heal("jing", j);
	
        message_combatd("$N深深吸了几口气，精神看起来好多了。\n", me);

        if( me->is_fighting() ) me->start_busy(1);
	
	return 1;
}
int help(object me)
{
	write(WHT"\n基本内功之提振精神："NOR"\n");
	write(@HELP

	使用功效：
		培植自己耗用的精气

	出手要求：
		基本内功
		内力20
HELP
	);
	return 1;
}

