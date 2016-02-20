// liuyun.c 流云七剑
// Last Modified by Sir on 5/17/2001

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「流云七剑」"
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail(PNAME"开始时必须拿着一把剑！\n");

	fskill = "baiyun-xinfa";
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

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的真气不够！\n");

	msg = HIC "$N运起恒山派行云流水，顺其自然的白云心法，手中"+weapon->query("name")+ HIC"顿时锋芒暴长，剑招连绵不绝涌上心头。瞬息之间，全身便罩在一团白雾之中。\n" NOR;
	message_combatd(msg, me);

//	attack_time = 3 + random(5);
		attack_time = 7;
    for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
			me->add("neili", -50);
		}
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
                行云流水般可连出七招

        出手要求：
                白云心法100级
                恒山剑法100级
                内力400
HELP
        );
        return 1;
}

