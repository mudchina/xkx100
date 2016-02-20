// Last Modified by winder on Jul. 9 2001
// yanxue.c  「烟雪春梅」
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「"HIW"烟雪春梅"NOR"」"
int perform(object me, object target)
{
	int damage;
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
		
		//兵器空手均可
		
	fskill = "bingxue-xinfa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 500 )
		return notify_fail("你的内力修为还不够高。\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的内力不够。\n");

	msg = HIW"$N"HIW"冰雪心法运转一周天，全身只觉一股寒气蒸腾欲出，清啸一声，\n飞身而上,施展出「"+HIW"烟雪春梅」，双手一搓一放,一股凝人气血的\n狂飙向$n"HIW"铺天盖地席卷而去。\n"NOR;
	if(random(me->query_skill(bskill, 1)) > target->query_skill("parry",1)/3)
	{ 
		me->start_busy(1+random(1));
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1)+(int)me->query_skill("force",1)*2;
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -300);
		msg +=HIC"$n只见漫天青气席卷而来，躲无可躲，卒一接触，便被震得七窍流血，如断线风筝向后飘去。\n"NOR;
	} else
	{
		me->start_busy(2+random(1));
		msg += HIC"可是$p看破了$P的企图，轻轻地闪在了一边。\n"NOR;
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
                伤敌气血

        出手要求：
                冰雪心法50级
                飞雪映梅掌50级
                内力修为500
                内力400
HELP
        );
        return 1;
}

