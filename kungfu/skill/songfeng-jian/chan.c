// chan.c 松风剑法「缠」字诀
// Last Modified by winder on Aug. 13 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「缠」字诀"
int perform(object me, object target)
{
	object weapon;
	string msg;
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
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	fskill = "qingming-xuangong";
	bskill = "sword";
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

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够，不会使用「缠」字诀。\n");

	msg = HIG"$N"HIG"使出松风剑法「缠」字诀，将手中剑搭在$n"HIG"兵刃上，剑随意转，连绵不绝，使$n"HIG"一时无法变招。\n";
	
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4) 
	{
		msg += HIR "结果$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
		target->start_busy((int)me->query_skill("sword", 1)/30);
	        me->add("neili", -150);  // -200
	} else {
		msg +=HIY"可是$p看破了$P的企图，镇定逾恒，一振振开了$P的剑，全神应对自如。\n" NOR;
		me->start_busy(1);
		me->add("neili", -50);  // -100
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		青冥玄功50级
		松风剑法40级
		内力300
HELP
	);
	return 1;
}

