// transfer.c 转内力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me, object target)
{
	int force, trans;

	if( query_ip_name(target)==query_ip_name(me))
		return notify_fail("你只能将真气传给其他玩家。\n");

	if( !target || target==me ||
		!living(target) || target->query_temp("noliving") )
		return notify_fail("你要将真气传给哪位？\n");

	if(me->query_skill_mapped("force")!=target->query_skill_mapped("force"))
		return notify_fail(target->name()+"所使用的内功和你不同，不能传内力。\n");

	if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
		return notify_fail("你的真气不足。\n");

	if( (int)me->query("max_neili") <= (int)target->query("max_neili") )
		return notify_fail("你的真气还不如人家多，传不过去。\n");

	if ((int)target->query("neili") >= (int)target->query("max_neili")*2)
		return notify_fail("对方的真气充沛，不需要你的真气。\n");
  if (target->is_busy())
   return notify_fail("对方正忙着呢。\n");
	force = me->query("neili") - (me->query("max_neili")/3);

	if( (int)force/3 < 1 ) return notify_fail("你的真气不足。\n");
	me->add("neili", -(int)force/3 );
	me->start_busy(3);
	if( (int)me->query("max_neili") <= (int)target->query("max_neili")*5/4 )
		me->add("max_neili", -1);

	message_combatd(HIW"$N一掌拍在$n背心，顺势运气将体内真气传送过去。\n"NOR, me,target);
	target->add("neili", (int)force/3);
	target->start_busy(3);
	tell_object(target, HIW "你觉得一股热气从"+me->name()+"的手掌中传了过来。\n" NOR);
	return 1;
}

int help(object me)
{
	write(WHT"\n基本内功之传送内力："NOR"\n");
	write(@HELP

	使用功效：
		将自己的内力传送到别人体内　
		若接受方内力上限达到传送方的八成，将损耗传送方内力上限

	出手要求：
		基本内功
		内力20
		双方是不同的ip
		双方修习同一种内功
		接受方最大内力小于传送方
HELP
	);
	return 1;
}

