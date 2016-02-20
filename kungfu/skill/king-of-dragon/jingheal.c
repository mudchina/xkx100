// jingheal.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	if ( !wizardp(this_player()) )
		return notify_fail("你无权进行精的治疗！\n");

	if( !target )
		return notify_fail("你要用真气为谁疗伤？\n");

	message_combatd(
		HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

	target->set("eff_jing", target->query("max_jing"));
	target->set("jing",target->query("max_jing"));


	return 1;
}
