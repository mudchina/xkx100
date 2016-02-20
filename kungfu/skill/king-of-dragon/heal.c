// heal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_busying() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	if ( !wizardp(me)) return 0 ;
	write( HIY "你全身放松，坐下来开始运功疗伤。\n" NOR);
	message("vision", HIY + me->name() + "吐出一口金灿灿的血，脸色立刻恢复了正常。\n" NOR, environment(me), me);

	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("jingli", (int)me->query("max_jingli"));
	return 1;
}
