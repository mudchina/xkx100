// pangen.c 铁掌掌法 「枯树盘根」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「枯树盘根」"
int perform(object me, object target)
{
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
		
	if( me->query_temp("weapon") )
		return notify_fail("只有空手才能施展「枯树盘根」。\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能使"+PNAME+"。\n");

	if((int)me->query("max_neili") < 500)
		return notify_fail("你内力修为不够，不能使用枯树盘根！\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够，不能使用枯树盘根！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");
	msg = HIY"$N使出铁掌掌法的「枯树盘根」，左掌猛地向$n的双手抓去！\n"NOR;
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY"结果$P发现$p两手殊非血肉之物，被$p一挣就挣脱了。\n"NOR;
			me->start_busy(random(3) + 1);
			me->add("neili", -200);
		} else {
			msg += HIG"结果$p的双手被$P一把揽住，动弹不得！\n"NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30) + 2);
			me->add("neili", -300);
		}
	}
	else
	{
		msg += HIY "结果$p两手急收，$P的出手扑了个空！\n"NOR;
		me->add("neili", -200);
		me->start_busy(4);
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
		迟滞对方出手

	出手要求：
		归元吐纳法100级
		铁掌掌法100级
		内力修为500
		内力300
HELP
	);
	return 1;
}

