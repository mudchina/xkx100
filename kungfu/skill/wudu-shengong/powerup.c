// powerup.c 化蛇大法
// Last Modified by winder on Mar. 10 2000
//modified by sega 12/28/1999
//改了增加功力与降低不等和不耗内力的bug

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/wudu-shengong/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( target != me )
		return notify_fail("你只能用五毒神功提升自己的战斗力。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

	me->add("neili",-100);
	message_combatd(BLU"$N运起五毒神功，头顶黑气蒸腾，全身肌肤坟起黑色的鳞甲，双目凶光四射！\n" NOR, me);

	me->add_temp("apply/armor", skill);
	me->add_temp("apply/hand", skill/3);
	me->add_temp("apply/attack", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill:), skill);

	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/hand", -amount/3);
		me->add_temp("apply/attack",-amount/3);
		me->add_temp("apply/armor",-amount);
		me->delete_temp("powerup");
		tell_object(me, "你的五毒神功运行完毕，身体逐渐恢复正常。\n");
	}
}
int help(object me)
{
	write(WHT"\n五毒神功之化蛇大法："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻击防御能力

	出手要求：
	        内力100
HELP
	);
	return 1;
}

