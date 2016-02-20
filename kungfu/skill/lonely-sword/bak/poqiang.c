// poqiang.c 「破枪式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;

	if(me->query("family/master_id") != "feng qingyang")
	   return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if( !(me->is_fighting() ))
	    return notify_fail("「破枪式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
	    return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")) ||
	    ((string)weapon2->query("skill_type") != "spear" &&
	     (string)weapon2->query("skill_type") != "club" &&
	     (string)weapon2->query("skill_type") != "staff"))
	    return notify_fail("对方没有使枪棒，你用不了「破枪式」。\n");

	if( skill < 50)
	    return notify_fail("你的独孤九剑等级不够, 不能使用「破枪式」！\n");

	if( me->query("neili") < 50 )
	    return notify_fail("你的内力不够，无法运用「破枪式」！\n");

	msg = HIC "$N一式独孤九剑「破枪式」，剑势灵巧地顺着"+weapon2->name()
+"削落，划向$n的五指。\n";
	message_combatd(msg, me, target);
	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	if((string)weapon2->query("skill_type") == "staff")
	    dp = target->query_skill("staff") / 2;
	else if((string)weapon2->query("skill_type") != "club")
	    dp = target->query_skill("club") / 2;

	if( dp < 1 )
	    dp = 1;
	if( random(ap) > dp )
	{
	    if(userp(me))
		 me->add("neili",-50);
	    msg = "$N运起「破枪式」, $n顿时大惊，为保手指，手中";
	    msg += weapon2->name();
	    msg += "撒手丢出！\n" NOR;

	    me->start_busy(random(2));
	    target->receive_damage("qi", damage);
	    target->start_busy(2);
	    weapon2->move(environment(me));
	}
	else
	{
	    if(userp(me))
		 me->add("neili",-30);
	    msg = "可是$n看破了$N的剑路，舍命将手中" + weapon2->name()+
"向前急刺，迫使$N收回攻势！\n"NOR;
	    me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之破枪式："NOR"\n");
	write(@HELP

	使用功效：
		破解且可击落手持枪类兵器的敌手之兵器，并伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑50级
		内力50
HELP
	);
	return 1;
}

