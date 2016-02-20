// lifeheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if( !wizardp (me)) return 0;
	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	message_combatd( HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR, me, target );

	target->set("eff_qi", target->query("max_qi"));
	target->set("qi", target->query("max_qi"));

	return 1;
}
