// reserve.c 蛤蟆功经脉倒转
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

int exert(object me, object target)
{
	object weapon;
	int skill;
	string msg;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/reserve") &&
  !me->query("can_perform/hamagong/reserve") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

        if ( me->query("family/master_id") != "ouyang feng" )
		return notify_fail("你目前还没有这个功力，小心走火入魔。\n");
		
	if( (int)me->query_skill("hamagong", 1) < 160 )
		return notify_fail("你的蛤蟆功不够娴熟，不会经脉倒转。\n");

	if( (int)me->query("neili") < 200  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("hmg_dzjm") ) 
		return notify_fail("你已经倒转经脉了。\n");

	skill = me->query_skill("hamagong",1);
	msg = HIB "$N忽地双手撑地倒立，逆运经脉，顿时内息暗生，防御力大增。\n"NOR;
	message_combatd(msg, me, target);

	me->add_temp("apply/attack", -skill/6);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("hmg_dzjm", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/6, skill/2 :), skill);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("hmg_dzjm");
	tell_object(me, HIY "你双手一撑，一跃而起，将内力收回丹田。\n"NOR);
}
int help(object me)
{
	write(WHT"\n蛤蟆功之经脉倒转："NOR"\n");
	write(@HELP

	使用功效：
		倒转经脉，规避点穴

	出手要求：
		蛤蟆功160级
		内力200
HELP
	);
	return 1;
}


