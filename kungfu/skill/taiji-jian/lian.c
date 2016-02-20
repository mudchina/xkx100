// lian.c 太极剑法「连」字诀
// Last Modified by sega on 4.10 2000
//减弱到10剑,不然太可怕了点.

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

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"没有娴熟到能使"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不够了，不能使用「连」字诀。\n");

	msg = HIY "$N使出太极剑法「连」字诀，招式陡然变快。\n";

	if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/20)
	{
		attack_time = random((int)me->query_skill("sword", 1) / 20);
	        sword_lvl =(int)me->query_skill("sword", 1)/15;
         	if(attack_time < 2) attack_time = 2;
		if(attack_time >10) attack_time = 10;
		if(attack_time > 5) 
		{ attack_time = attack_time - 4;
		  attack_time = 5 + random(attack_time);
		 } 
		msg += CYN " 结果$p被$P攻了个措手不及，连连后退不暇！\n" NOR;
		message_combatd(msg, me, target);
		for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			me->add_temp("apply/dodge",sword_lvl);
			me->add_temp("apply/attack",sword_lvl);
			me->add_temp("apply/sword",sword_lvl);
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
		}
		me->add_temp("apply/dodge",-i*sword_lvl);
		me->add_temp("apply/attack",-i*sword_lvl);
		me->add_temp("apply/sword",-i*sword_lvl);
		me->start_busy(1);
		me->add("neili", -30*i);
	}
	else
	{
		msg += "可是$p看破了$P的企图，抢先下手制住了$P的连续后招。\n" NOR;
		message_combatd(msg, me, target);
		me->start_busy(2);
		me->add("neili", -150);
	}

//	if(!target->is_fighting(me)) target->fight_ob(me);
	if(flag != 1) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出剑攻击对方

	出手要求：
		太极神功70级
		太极剑法50级
		内力150
HELP
	);
	return 1;
}

