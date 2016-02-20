// chan.c 打狗棒法「缠」字诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「缠」字诀"
inherit F_SSERVER;
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "stick")
		return notify_fail("你使用的武器不对。\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧。\n");

	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够深厚，不会使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");
	if(me->query("max_neili") < 400)
		return notify_fail("你的内力修为不够，不会使用"PNAME"。\n");
	if(me->query("neili") < 300)
		return notify_fail("你的内力修为不够，不会使用"PNAME"。\n");
	msg = HIG"$N"HIG"使出打狗棒法「缠」字诀，棒头在地下连点，连绵不绝地挑向$n"HIG"的小腿和脚踝。\n";

	me->start_busy(1);
	me->add("neili", -200);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 )
	{
		msg += HIR " 结果$p被$P攻的蹦跳不停，手忙脚乱！\n" NOR;
		target->start_busy( (int)me->query_skill(bskill, 1) / 20 );
	} else {
		msg += "可是$p看破了$P的企图，镇定解招，一丝不乱。\n" NOR;
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
		混天气功100级
		打狗棒法100级
		内力修为400
		内力300
HELP
	);
	return 1;
}

