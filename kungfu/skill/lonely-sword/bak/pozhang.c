// pozhang.c 「破掌式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, wound;

	if(me->query("family/master_id") != "feng qingyang")
	   return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if( !(me->is_fighting() ))
	    return notify_fail("「破掌式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
	    return notify_fail("你使用的武器不对。\n");

	if (objectp(weapon2 = target->query_temp("weapon")))
	    return notify_fail("对方手里拿了武器，你用不了「破掌式」。\n");

	if( skill < 70)
	    return notify_fail("你的独孤九剑等级不够, 不能使用「破掌式」！\n");

	if( me->query("neili") < 50 )
	    return notify_fail("你的内力不够，无法运用「破掌式」！\n");

	msg = HIC "$N使出独孤九剑之「破掌式」, 劲力聚在剑尖，企图以意使剑.\n";
	message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 1000;
	dp = target->query("combat_exp") / 4;
	if( dp < 1 )
	    dp = 1;
	if( random(ap) > dp )
	{
	    if(userp(me))
		 me->add("neili",-50);
	    msg = "$N运起「破掌式」, $n顿时觉得眼前一花，手心一凉，手掌中心一
截剑尖冒了出来。\n"NOR;

//	    wound = 60 + random(skill);
	    wound = (int)me->query_skill("sword",1)/2 + skill;
	    wound = wound/2 + random(wound);
// modify by Java
	    if( wound > (int)target->query("qi"))
		wound = (int)target->query("qi");
	    me->start_busy(random(2));
//	    target->add("qi", -wound);
//	    target->add("eff_qi", -wound);
	    target->receive_damage("qi", wound);
	    target->receive_wound("qi", wound/2);
// modify by Java
	    target->start_busy(2);
	}
	else
	{
	    if(userp(me))
		me->add("neili",-100);
	    msg = "可是$n看破了$N的企图，全力防守，堪堪抵住了$N的攻势。\n"NOR;
	    me->start_busy(random(3));
	}
	message_combatd(msg, me, target);
	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之破掌式："NOR"\n");
	write(@HELP

	使用功效：
		破解空手搏击的敌手之招数，并伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑50级
		内力50
HELP
	);
	return 1;
}

