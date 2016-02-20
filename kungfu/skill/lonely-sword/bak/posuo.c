// posuo.c 「破索式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, wound, damage;

	if(me->query("family/master_id") != "feng qingyang")
	   return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if( !(me->is_fighting() ))
	    return notify_fail("「破索式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
	    return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "whip")
	    return notify_fail("对方没有使索，你用不了「破索式」。\n");

	if( skill < 60)
	    return notify_fail("你的独孤九剑等级不够, 不能使用「破索式」！\n");

	if( me->query("neili") < 50 )
	    return notify_fail("你的内力不够，无法运用「破索式」！\n");

	msg = HIC "$N使出独孤九剑之「破索式」，剑化流星，迅急无比地点向$n的手腕。\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("whip") / 2;
	if( dp < 1 )
	    dp = 1;
	if( random(ap) > dp )
	{
	    if(userp(me))
		 me->add("neili",-50);
	    msg = "结果$n被$p攻了个措手不及，手腕一麻，手中";
	    msg += weapon2->name();
	    msg += "脱手而出！\n" NOR;

	    me->start_busy(random(2));
	    target->receive_damage("qi", damage);
	    target->start_busy(2);
	    weapon2->move(environment(me));
/*
	    if (weapon2->query("ownmake")==1)
	    {
		weapon2->move(target);
		msg += "那可是$n的随身家伙！$n手一伸将它捡回来。\n" NOR;
	    }
*/
       }
	else
	{
	    if(userp(me))
		 me->add("neili",-30);
	    msg ="可是$n看破了$N的企图，迅即退开，使$N的「破索式」没有起到作用。\n"NOR;
		 me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之破索式："NOR"\n");
	write(@HELP

	使用功效：
		破解且可击落手持索类兵器的敌手之兵器，并伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑60级
		内力50
HELP
	);
	return 1;
}

