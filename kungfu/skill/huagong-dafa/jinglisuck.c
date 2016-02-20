// jinglisuck.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;
	int my_max, tg_max;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/jinglisuck") &&
  !me->query("can_perform/huagong-dafa/jinglisuck") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");
	if ( target == me ) target = offensive_target(me);


	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

	if( !objectp(target) ||
		target->query("id") == "gongping zi" ||
		target->query("id") == "zhang men" ||
		target->query("id") == "mu ren" ||
		target->query("id") == "shi ren" ||
		target->query("id") == "jiguan ren" ||
		target->query("id") == "xiangpi ren" ||
		target->query("id") == "jin ren" ||
		target->query("id") == "du jiangshi")
		return notify_fail("你要吸取谁的精力？\n");
	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	if (target->query("race") != "人类")
		return notify_fail("搞错了！只有人才能有精力！\n");

	my_max = me->query("max_jingli");
	tg_max = target->query("max_jingli");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过精力！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人精力！\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 100 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的精力！\n");

	if( (int)me->query("neili",1) < 20 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("max_jingli") < 10 )
		return notify_fail( target->name() +
			"精力涣散，功力未聚，你无法从他体内吸取任何东西！\n");

	if( (int)target->query("max_jingli") < (int)me->query("max_jingli")/10 )
		return notify_fail( target->name() +
			"的内功修为远不如你，你无法从他体内吸取精力！\n");

	message_combatd(
		HIR "$N全身骨节爆响，双臂暴长数尺，掌缘猛地向$n的天灵拍了下去！\n\n" NOR,
		me, target );

        if ( living(target) && !target->query_temp("noliving") )
	{
		if( !target->is_killing(me) ) target->kill_ob(me);
	}

	sp = me->query_skill("force") + me->query_skill("dodge") + me->query_skill("zhaixinggong",1)/2;
	dp = target->query_skill("force") + target->query_skill("dodge");

	me->set_temp("sucked", 1);		

	if (( random(sp) > random(dp) ) ||
		!living(target) || target->query_temp("noliving") )
	{
		tell_object(target, HIR"你只觉天顶骨裂，全身功力贯脑而出，如融雪般消失得无影无踪！\n" NOR);
		tell_object(me, HIG"你觉得" + target->name() + "的精力自手掌源源不绝地流了进来。\n" NOR);

		target->add("max_jingli", -1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
		if ((int)me->query("max_jingli") <
                    ((int)me->query_skill("taoism",1) * 10))
		{
			me->add("max_jingli", 1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
			me->add("jingli", 1*(1+(me->query_skill("huagong-dafa", 1)-100)/5) );
		}
		if( target->query("max_jingli") <1) target->set("max_jingli",0);

//		if( (int)me->query("potential") - (int)me->query("learned_points") < 90 ) 
		me->add("potential",  3);
		me->add("combat_exp", 10);

		me->start_busy(7);
		target->start_busy(random(7));
		me->add("neili", -10);

		call_out("del_sucked", 10, me);
	}
	else
	{	
		message_combatd(HIY "可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(7);
		call_out("del_sucked", 20, me);
	}

	return 1;
}

void del_sucked(object me)
{
	if ( me->query_temp("sucked") )
	me->delete_temp("sucked");
}

int help(object me)
{
	write(WHT"\n化功大法之吸取精力："NOR"\n");
	write(@HELP

	使用功效：
		吸取对方精力
		增强自己精力

	出手要求：
		化功大法100级
		内力20
HELP
	);
	return 1;
}

