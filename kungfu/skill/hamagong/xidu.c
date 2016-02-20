// 蛤蟆功吸毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me,object target)
{
	int con1, con2, con3, con;
	con1 = target->query_condition("snake_poison");
//	con2 = target->query_condition("scorpion_poison");
	con3 = target->query_condition("xx_poison");

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/xidu") &&
  !me->query("can_perform/hamagong/xidu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");


	if ( !living(target) || target == me )
		return notify_fail("你要为谁吸毒？\n");
		
	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if ( !con1 && !con3 )
		return notify_fail("对方没有中毒！\n");

        if ( target->is_fighting() )
		return notify_fail("战斗中无法运功吸毒！\n");
		
	if( me->is_fighting() )
		return notify_fail("战斗中运功吸毒？找死吗？\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if ((int)me->query_skill("hamagong", 1) < 50)
		return notify_fail("你的蛤蟆功修为还不够。\n");

	if ((int)me->query_skill("xidu-poison", 1) < 50)
		return notify_fail("你的西毒毒技修为还不够。\n");

	if ( con1 > 0 ) {
		if ( (int)me->query("neili") < 100 )
			return notify_fail("你的真气不够。\n");
		con = ( ( me->query_skill("hamagong", 1) / 10 ) >= con1 ? con1 : me->query_skill("hamagong", 1) / 10 );
		target->apply_condition("snake_poison", con1 - con);
		message_vision(  HIW "$N盘膝坐下将手掌贴在$n背心，运功将$n体内的蛇毒吸出...\n片刻功夫，$N的掌心已全呈黑色。\n" NOR , me, target );
//		if ( !con1 )
    if ( (con1 - con)<=0 )
			{
				tell_object( target, HIC "你活动了一下筋骨，发觉全身的麻木感已完全消失了。\n\n" NOR );
		    target->clear_condition("snake_poison");
		  }
		else	
			tell_object( target, HIC "你活动了一下筋骨，发觉全身的麻木感减轻了不少。\n\n" NOR );			
		me->add("neili", -100);			
		me->apply_condition("snake_poison", me->query_condition("snake_poison") + con);
	}			 
	else if ( con3 > 0 ) {
		if ( (int)me->query_skill("hamagong", 1) < 70 )
			return notify_fail("你的蛤蟆功修为不够。\n");
		if ( (int)me->query("neili") < 150 )
			return notify_fail("你的真气不够。\n");
		con = ( ( me->query_skill("hamagong", 1) / 50 ) >= con3 ? con3 : me->query_skill("hamagong", 1) / 50 );
		target->apply_condition("xx_poison", con3 - con);
		message_vision(  HIW "$N盘膝坐下将手掌贴在$n背心，运功将$n体内的星宿掌毒吸出...\n"
			 "片刻功夫，$N的掌心已全呈紫黑色。\n" NOR , me, target );
//		if ( !con3 )
    if ( (con3 - con)<=0 )
			{
				tell_object( target, HIY "你只觉得一股暖流从丹田升起，全身热乎乎的，星宿掌毒似乎已全除尽了。\n\n" NOR );
		    target->clear_condition("xx_poison");
      }
		else	
			tell_object( target, HIY "你只觉得一股暖流从丹田升起，不似先前那般寒冷了。\n\n" NOR );			
		me->add("neili", -150);			
		me->apply_condition("xx_poison", me->query_condition("xx_poison") + con);
	}
	me->set("jiali", 0);
	me->start_busy(4);
	return 1;
}
int help(object me)
{
	write(WHT"\n蛤蟆功之吸毒："NOR"\n");
	write(@HELP

	使用功效：
		为中毒的他人吸出毒素，对下列毒有效：
		蛇毒、星宿毒

	出手要求：
		蛤蟆功50级
		西毒毒技50级
		内力100
HELP
	);
	return 1;
}

