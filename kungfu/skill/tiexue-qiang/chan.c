// chan.c 铁血枪法「缠绕」诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「缠绕」诀"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不对。\n");
		
	fskill = "guiyuan-tunafa";
	bskill = "spear";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够，使不出"+PNAME+"。\n");

	if (me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不足，使不出「缠绕」诀。\n");

	if (me->query("neili") < 200 )
		return notify_fail("你的内力不足，使不出「缠绕」诀。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	msg = CYN "$N"CYN"使出铁血枪法「缠绕」诀，手中"+weapon->name()+CYN"如灵蛇扭动，在$n"CYN"的下三路挑、拨、撩、缠，\n";

	me->start_busy(random(3));
	me->add("neili", -150);
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		msg += "结果$p被$P搞的心情大乱，手忙脚乱起来！\n" NOR;
		target->start_busy( (int)me->query_skill(bskill) / 40);
	} else {
		msg += "$p不理$P的虚招，出手没有丝毫迟滞。\n" NOR;
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

int help(object me)
{
	write(WHT"\n铁血枪法之缠绕诀"NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		归元吐纳法50级
		铁血枪法50级
		内力修为300
		内力200
HELP
	);
	return 1;
}

