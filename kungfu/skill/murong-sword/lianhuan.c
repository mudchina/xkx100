// lianhuan.c 连环
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「七剑连环」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count,attack_time,i;
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
		return notify_fail("「七剑连环」开始时必须拿着一把剑！\n");

	fskill = "shenyuan-gong";
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
		return notify_fail("你的"+to_chinese(fskill)+"不够！无法使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练！无法使出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("canhe-finger",1) < 100 )
			return notify_fail("你的参合指不够精通！无法使出「七剑连环」！\n");
		if( (int)me->query_skill("finger",1) < 100 )
			return notify_fail("你的基本指法修为不够！无法使出「七剑连环」！\n");
	}

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	msg = HIC "$N"HIC"运起慕容世家行云流水，顺其自然的心法，手中"+weapon->query("name")+ HIC"顿时锋芒暴长，剑招连绵不绝涌上心头，不可遏止，就在手中使了出来。瞬息之间，全身便如罩在一道光幕之中。\n" NOR;
	message_combatd(msg, me);
	attack_time = 6 + random(2);
	for(i = 0; i < attack_time; i++)
	{
		if (flag==1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	}
	me->add("neili", -50*i);
	me->start_busy(2+random(3));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手六七剑

	出手要求：
		神元功100级
		基本剑法100级
		慕容剑法100级
		基本指法100级
		参合指100级
		内力500
HELP
	);
	return 1;
}

