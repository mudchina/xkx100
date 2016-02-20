// poanqi.c 破箭式
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("lonely-sword",1);

	if(me->query("family/master_id") != "feng qingyang")
	   return notify_fail("你不是风清扬的弟子，不能使用绝招！\n");

	if( !(me->is_fighting() ))
	    return notify_fail("「破箭式」只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
	    return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon2 = target->query_temp("weapon"))
	|| (string)weapon2->query("skill_type") != "throwing")
	     return notify_fail("对方没有使暗器，你用不了「破箭式」。\n");

	if( skill < 50)
	    return notify_fail("你的独孤九剑等级不够, 不能使用「破箭式」！\n");

	if( me->query("neili") < 50 )
	    return notify_fail("你的内力不够，无法运用「破箭式」！\n");

	msg = HIC "$N举剑连点，运起独孤九剑之「破箭式」, 将$n掷过来的"+ weapon2->name() + "打得向$n反击回去。\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = me->query_skill("sword") + skill;
	dp = target->query_skill("throwing", 1);
	if( dp < 1 )
		dp = 1;
	  if( random(ap) > dp )
	  {
	     if(userp(me))
		  me->add("neili",-50);
	     msg = "$n顿时觉得铺天盖地的";
	     msg += weapon2->name();
	     msg += "反而向自己袭来！全身上下立刻被打得跟马蜂窝似的\n" NOR;

	     me->start_busy(random(2));
	     target->receive_damage("qi", damage);
	     target->start_busy(2);
	}
	else
	{
	     if(userp(me))
		  me->add("neili",-30);
	     msg = "可是$n看破了$N的意图，立刻将手中" + weapon2->name()+
"舞得风雨不透，将反击回来的" + weapon2->name() + "尽数击落在地。\n"NOR;
	     me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
int help(object me)
{
	write(WHT"\n独孤九剑之破箭式："NOR"\n");
	write(@HELP

	使用功效：
		破解持暗器的对手，反激暗器伤敌气血

	出手要求：
		身为风清扬嫡传弟子
		独孤九剑100级
		内力50
HELP
	);
	return 1;
}

