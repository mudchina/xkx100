// fanchang.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fanchang") &&
  !me->query("can_perform/longxinag/fanchang") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");
		
	if( !objectp(target) ) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ) 
		return notify_fail("你要对谁使用梵唱？\n");
	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( (int)me->query_skill("longxiang",1) < 50 )
		return notify_fail("你的龙象般若功功力不够，不能凝神攻击对方！\n");

	if( (int)me->query("neili",1) < 50 )
		return notify_fail("你的内力不够，不能使用龙象般若功。\n");

	message_combatd(HIW "$N面无表情，歌声如梵唱般贯入$n耳中！\n\n" NOR, me, target );

        if( living(target) && !target->query_temp("noliving") )
		if( !target->is_killing(me) )
			target->kill_ob(me);

	sp = me->query_skill("force") + me->query_skill("lamaism") + me->query_skill("longxiang",1)/2;
	dp = target->query_skill("force");
	
	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIW"你忽然觉得脑中一片空白，不由自主地随歌声舞蹈起来！\n" NOR);
		tell_object(me, HIB"你看到" + target->name() + "随着你的歌声手舞足蹈，十分可笑。\n" NOR);

		target->receive_damage("jing", 10 + random((int)me->query_skill("longxiang", 1)) );
		
		if( target->query("combat_exp") >= me->query("combat_exp") )
				me->add("potential", 1);

		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -50);

	}
	else
	{	
		message_combatd(HIY "可是$p不为$P歌声所动，定力果然不同凡响！\n" NOR, me, target);
		me->start_busy(4);
	}

	return 1;
}
int help(object me)
{
	write(WHT"\n龙象般若功之梵唱："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方精气
		迟滞对方出手

	出手要求：
		龙象般若功50级
		内力50
HELP
	);
	return 1;
}

