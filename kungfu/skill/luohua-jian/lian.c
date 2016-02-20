// Last Modified by winder on Sep. 12 2001
// lian.c 红花十三剑法「连」字诀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「连」字诀"
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time,sword_lvl;
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

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够！\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的真气不够！\n");

	me->add("neili", -200);

	msg = HIY"$N"HIY"使出红花十三剑法「连」字诀，招式陡然变快，疯狂的扑向$n！\n"NOR;
	message_combatd(msg, me, target);
	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		attack_time = random((int)me->query_skill(bskill, 1)/20);
		sword_lvl=(int)me->query_skill(bskill,1)/10;
		if(attack_time < 2) attack_time = 2;
		if(attack_time > 10) attack_time = 10;
		if(attack_time > 5) 
		{
			attack_time = attack_time - 4;
			attack_time = 5 + random(attack_time);
		}

		msg = YEL"结果$p被$P一轮急攻，毫无还手余裕。\n"NOR;
		for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			me->add_temp("apply/dodge",sword_lvl);	
			me->add_temp("apply/attack",sword_lvl);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add_temp("apply/dodge",-sword_lvl*i);
		me->add_temp("apply/attack",-sword_lvl*i);
		me->start_busy(2);
		target->start_busy(1);
	}
	else
	{
		msg = CYN"可是$p出手在先，一下就制住了$P的剑路。\n"NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		对敌人连续出手

	出手要求：
		红花神功120级
		落花十三剑120级
		内力修为500
		内力400
HELP
	);
	return 1;
}

