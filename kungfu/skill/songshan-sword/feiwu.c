// Last Modified by Winder on May. 21 2001
// feiwu.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「飞舞」"
int perform(object me, object target)
{
	object weapon;
	int i,count;
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

	fskill = "hanbing-zhenqi";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"功力太浅，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"功力太浅，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"功力太浅，无法使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你的内力修为太浅，无法飞舞攻击。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够，无法飞舞攻击。\n");
		
	if( me->query_temp("ss_feiwu") )
		return notify_fail("你刚使完「飞舞」，目前气血翻涌，无法再次运用！\n");

	me->add("neili", -300);

	message_combatd(BLU"\n$N"BLU"突然长啸一声，运气寒冰真气，举剑挺刺，在半空中划出道道剑光，空中气劲激荡，阵阵寒气向$n"BLU"奔袭而去！\n" NOR,me, target);

	me->add_temp("apply/damage", 50);
	for(count=0;count<5;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
	}
	me->add_temp("apply/damage", -50);
	me->set_temp("ss_feiwu", 1); 
	i = (int)me->query_skill(bskill, 1)/30;
	if( 15 - i <= 4) i = 4;
	call_out("remove_effect", i, me);
	me->start_busy(1);

	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("ss_feiwu");
	tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「飞舞」了。\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		重手出手四剑

	出手要求：
		寒冰真气120级
		嵩山剑法120级
		基本剑法120级
		内力修为1500
		内力500
HELP
	);
	return 1;
}

