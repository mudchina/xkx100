// shengang.c 混天气功混天神罡
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/shengang") &&
  !me->query("can_perform/huntian-qigong/shengong") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( (int)me->query_temp("shengang") ) 
		return notify_fail(HIG"你已经在运混天神罡了。\n"NOR);

//	if( !me->is_fighting() )
//		return notify_fail("「混天神罡」只能在战斗中使用。\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的内力还不够！\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 150)
		return notify_fail("你的混天气功的修为不够，不能使用混天神罡! \n");
//必须有兵器。加兵器威力
	msg = HIY "$N使出混天气功「混天神罡」，将真气贯注到手心！\n" NOR;

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("huntian-qigong",1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
		message_combatd(msg, me, target);
		me->add_temp("apply/damage", skill*2);
		me->set_temp("shengang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill*2 :), skill);

		me->add("neili", -150);
	}
	else
	{
		msg = HIR"$N拼尽毕生功力想提起混天神罡，但自己受伤太重，没能成功！\n" NOR;
	}
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("shengang") ) 
	{
		me->add_temp("apply/damage", - amount);
		me->delete_temp("shengang");
		tell_object(me, HIY "你的混天神罡运行完毕，将内力收回丹田。\n" NOR);
		me->start_busy(random(4));
	}
}
int help(object me)
{
	write(WHT"\n混天气功之混天神罡："NOR"\n");
	write(@HELP

	使用功效：
		加重自己的出手威力

	出手要求：
		混天气功150级
		内力400
HELP
	);
	return 1;
}

