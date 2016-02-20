// powerup.c 龙相功加力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	int i,lx,num;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/longxiang/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( target != me )
		return notify_fail("你只能提升自己的战斗力。\n");
	if( (int)me->query("neili")<200)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");
/*
    “龙象般若功”共分十三层，第一层功夫十分浅易，纵是下愚
之人，只要得到传授，一二年中即能练成。第二层比第一层加深一
倍，需时三四年。第三层又比第二层加深一倍，需时七八年。如此
成倍递增，越是往后，越难进展。待到第五层以后，欲再练深一层，
往往便须三十年以上苦功。
一层 2 
二层 4
三   8
四   16
五   32
六   32
七   32
八   32

*/
	lx = me->query_skill("longxiang",1);
	for(num=0,i=0;i<13;i++)
	{
		if (lx < 0) break;
		switch(i)
		{
			case 0: lx -= 2;num++;break;
		  case 1: lx -= 4;num ++;break;
		  case 2: lx -= 8;num ++;break;
		  case 3: lx -= 16;num ++;break;
		  default : lx -= 32;num ++;break;
		}
	}

//	message_combatd(HIR"$N大喝一声，全身骨骼节节暴响，一股迅猛的罡气向四周扩散开来！\n"NOR, me);
	message_combatd(HIR"$N口中默念大明六字真言，手结摩利支天愤怒印，运起"+chinese_number(num)+"龙"+chinese_number(num)+"象之力！\n"NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的龙象般若功运行完毕，将内力收回丹田。\n");
	}
}
int help(object me)
{
	write(WHT"\n龙象般若功之加力："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻击防御能力

	出手要求：
	        内力200
HELP
	);
	return 1;
}

