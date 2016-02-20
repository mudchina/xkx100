// lian.c 连环拳
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>
#define PNAME "「连环拳」"
inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg;
	int count;
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
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail(PNAME"不能持兵刃！\n");
		
	fskill = "xiantian-qigong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");
	msg = HIY "$N"HIY"已然领悟了「先天纯阳」之真义，「连环拳」出拳愈来愈急，毫
无停顿滞涩之感！\n" NOR;
	message_combatd(msg, me);
	
	for(count=0;count<3;count++)
	{
		if (flag == 1) target = offensive_target(me);
		if (objectp(target))		
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->add("neili", -100);
	me->start_busy(random(2));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手三招

	出手要求：
		先天气功140级
		纯阳拳135级
		内力100
HELP
	);
	return 1;
}

