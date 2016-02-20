// Last Modified by winder on Sep. 12 2001
// chan.c 缠字诀

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
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧。\n");

	fskill = "honghua-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你的内力修为不够！\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的真气不够！\n");

	msg = HIG"$N使出落花十三剑「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";

	me->start_busy(1);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 )
	{
		msg += HIR "结果$p被$P攻了个措手不及！\n" NOR;
		target->start_busy( (int)me->query_skill(bskill,1) / 30 );
	} else {
		msg += "可是$p神定气闲，看破了$P的企图。\n" NOR;
	}
	me->add("neili", -100);
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对手出招

	出手要求：
		红花神功40级
		落花十三剑40级
		内力修为300
		内力200
HELP
	);
	return 1;
}

