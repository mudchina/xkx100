// ciwan.c 刺腕
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>
#define PNAME "「刺腕」"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail(HIY "没剑你拿什么东西去刺人家？\n" NOR);

	fskill = "kuihua-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");
	if((int)me->query("max_neili") < 600)
		return notify_fail(HIY "你的内力修为还不够火候。\n" HIY);
	if((int)me->query("neili") < 400)
		return notify_fail(HIY "你现在真气不足。\n" HIY);
	if (target->query_temp("bixie/ciwan"))
		return notify_fail(HIR"对方已经身中「刺腕」了！\n"NOR);

	msg = HIC "$N"HIC"突然手中"+weapon->name()+HIC"一振，剑尖飞鹰扑兔般点向$n"HIC"手腕要害，\n"NOR;
	if (random(me->query_dex()) > target->query_dex()/2)
	{
		msg += HIC"$n"HIC"只觉得手腕一麻，一阵无力地垂了下去！\n"NOR;
		message_combatd(msg, me, target);
		me->add("neili", -400);
		target->set_temp("bixie/ciwan", 1);
		call_out("ciwan_end", (int) 6+random(6), target);
	} else
	{
		me->start_busy(2);
		me->add("neili", -300);
		msg += HIY"$n"HIY"疾忙一侧手，恰恰避过了$N的出手一击。\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

void ciwan_end( object target)
{
	message_combatd(HIR"$N"HIR"觉得手腕上渐渐又有了力气，忙抬手出招。\n"NOR, target);
	target->delete_temp("bixie/ciwan");

	return;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
        施招刺对方的手腕要害
		暂时性使对方失去招架能力
		暂时性使对手不能运用外功

	出手要求：
		辟邪剑法120级
		葵花心法100级
        最大内力600
		内力400
HELP
	);
	return 1;
}

