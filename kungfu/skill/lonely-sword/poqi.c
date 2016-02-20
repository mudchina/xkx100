// poqi.c 破气式
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, neili_wound, qi_wound;

	if(me->query("family/master_id") != "feng qingyang" && userp(me))
		return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");
	skill = me->query_skill("lonely-sword",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/poqi") &&
  !me->query("can_perform/lonely-sword/poqi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("「破气式」只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
	if( skill < 100)
		return notify_fail("你的独孤九剑等级不够, 不能使用破气式！\n");
	if( me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够，无法运用「破气式」！\n");
	if( me->query("neili") < 250 )
		return notify_fail("你的内力不够，无法运用「破气式」！\n");
	msg = HIC "$N潜运独孤九剑「破气式」，运气贯剑使其由利返钝，毫无花俏地直
刺$n的丹田。\n";
	message_combatd(msg, me, target);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-150);
		msg ="$N运起「破气式」，长剑斜挑对方小腹，$n顿时觉得眼前一花，气海穴\n上微微一痛，全身真气狂泄而出！\n" NOR;
		neili_wound = 300 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		qi_wound = skill+(int)me->query_skill("sword",1)/2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi")) qi_wound = 100;
		target->add("neili", -neili_wound);
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->set_temp("lonely-sword/poqi",1);
		target->start_busy(2);
		me->start_busy(2);
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg = "可是$n看破了$N的企图，立刻守紧门户，几经艰难终于还招挡开。\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之破气式："NOR"\n");
	write(@HELP

	使用功效：
		破解身具高深内功的敌手之武功，并伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑100级
		内力修为500
		内力250
HELP
	);
	return 1;
}

