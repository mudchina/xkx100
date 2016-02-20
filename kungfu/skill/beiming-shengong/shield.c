// shield.c 北冥神功护体神功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shield") &&
  !me->query("can_perform/beiming-shengong/shield") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( target != me ) 
		return notify_fail("你只能用北冥神功来提升自己的防御力。\n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_skill("beiming-shengong",1) < 40 ) 
		return notify_fail("你的北冥神功修为不够。\n");

	if( (int)me->query_temp("shield") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIW"$N双手平举过顶，运起北冥神功，全身笼罩在劲气之中！\n" NOR, me);

	me->add_temp("apply/armor", skill);
	me->set_temp("shield", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if( me->is_fighting() ) me->start_busy(2); 
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/armor", - amount);
	me->delete_temp("shield");
	tell_object(me, "你的北冥护体神功运行完毕，将内力收回丹田。\n");
}

int help(object me)
{
	write(WHT"\n北冥神功之护体神功："NOR"\n");
	write(@HELP

	使用功效：
		增强自己的防护力

	出手要求：
		北冥神功40级
		内力100
HELP
	);
	return 1;
}

