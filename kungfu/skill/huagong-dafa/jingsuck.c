// jingsuck.c
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
int exert(object me, object target)
{
	int sp, dp;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/jingsuck") &&
  !me->query("can_perform/huagong-dafa/jingsuck") && 
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
		return notify_fail("你要吸取谁的精气？\n");

	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if (target->query("race") != "人类")
		return notify_fail("搞错了！只有人才能有精气！\n");

	if ( me->query_temp("sucked") )
		return notify_fail("你刚刚吸取过精气！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能施用化功大法吸人精气！\n");

//	if( !me->is_fighting() || !target->is_fighting())

	if( (int)me->query_skill("huagong-dafa",1) < 45 )
		return notify_fail("你的化功大法功力不够，不能吸取对方的精气。\n");

	if( (int)me->query("neili",1) < 10 )
		return notify_fail("你的内力不够，不能使用化功大法。\n");

	if( (int)target->query("jing") < 45 )
		return notify_fail( target->name() +
			"已经精气涣散，你已经无法从他体内吸取精气了！\n");

	message_combatd(
		HIR "$N突然神秘的一笑，双掌一前一後对准$n的太阳穴拍了过来！\n\n" NOR, me, target );

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
		tell_object(target, HIR"你猛觉额角两侧如针刺般剧痛，神志迷困，头脑中一片空白！\n" NOR);
		tell_object(me, HIG"你觉得" + target->name() + "的精气自手掌源源不绝地流了进来。\n" NOR);

		target->receive_damage("jing", (int)me->query_skill("huagong-dafa", 1) );
		me->add("jing", (int)me->query_skill("huagong-dafa", 1) );
		me->add("eff_jing", (int)(me->query_skill("huagong-dafa", 1)*2/3) );
		if ( me->query("eff_jing") > me->query("max_jing") ) me->set("eff_jing", me->query("max_jing"));

		if( target->query("combat_exp") >= me->query("combat_exp") )
		{
//			if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
				me->add("combat_exp", 1);
		}

		me->start_busy(3);
		target->start_busy(random(3));
		me->add("neili", -5);

		call_out("del_sucked", 2, me);
	}
	else
	{	
		message_combatd(HIY"可是$p看破了$P的企图，内力猛地一震，借势溜了开去。\n" NOR, me, target);
		me->start_busy(3);
		call_out("del_sucked", 4, me);
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
	write(WHT"\n化功大法之吸取精气："NOR"\n");
	write(@HELP

	使用功效：
		吸取对方精气
		增强自己精气

	出手要求：
		化功大法45级
		内力10
HELP
	);
	return 1;
}

