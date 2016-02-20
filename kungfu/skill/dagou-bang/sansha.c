// sansha.c 三记杀招
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「三记杀招」"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
 	int i;
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
	if( (int)me->query_skill(fskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(fskill)+"功力不足，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");
	if( (int)me->query("max_neili") < 800 )
		return notify_fail("你的内力修为不够！\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的真气不够！\n");
	msg = HIY "$N"HIY"一声低吼，连续使出打狗棒法「三记杀招」！\n" NOR;
	message_combatd(msg, me);

	count = (int)(me->query_skill(bskill,1)/10);
	me->add("neili", -500);
	me->set_temp("apply/strength", count * 2);
	me->set_temp("apply/dexerity", 0-count);

	for(i=0;i<3;i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	}

	me->start_busy(1);
	me->add_temp("apply/strength", -count*2);
	me->add_temp("apply/dexerity",  count);

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
		连续出手三招

	出手要求：
		混天气功200级
		打狗棒法200级
		内力修为800
		内力600
HELP
	);
	return 1;
}

