// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「"HIW"雪花六出"NOR"」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count,i,attack_time,addatk;
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

	fskill = "bingxue-xinfa";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为还不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够！\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的真气不够！\n");

	msg = HIY"$N一抖手中长剑，一式"HIW"「雪花六出」"HIY"，连续刺出六剑，剑剑快如流星，\n幻成雪花六点，带起一阵寒飚向前疾飘而去。\n"NOR;
	message_combatd(msg, me);
	addatk= 10 + random(10);
	me->add_temp("apply/attack", addatk);
//	me->clean_up_enemy();
//	ob = me->select_opponent();

	attack_time = 3 + random(4);
	for(i = 0; i < attack_time; i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);	
	}
	me->add("neili", -30*attack_time);
	me->start_busy(1);

	me->add_temp("apply/attack", -addatk);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手六招

	出手要求：
		冰雪心法50级
		雪山剑法50级
		基本剑法50级
		内力修为500
		内力400
HELP
        );
        return 1;
}

