// hua.c 化骨绵掌
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「辣手化骨」"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
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

	if( me->query_temp("weapon") )
		return notify_fail("只有空手才能施展"PNAME"。\n");

	fskill = "dafa";
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
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你的内力不够，不能化骨。\n");

	msg = MAG "$N"MAG"掌出如风轻轻落在$n"MAG"肩头上。\n"NOR;

  me->add("neili", -100);
	me->start_busy(1);
	if( random( (int)me->query_skill(sskill,1)) > random(target->query_skill("dodge"))/2 )
	{
		msg += MAG "结果只听扑的一声，$p被$P一掌拍中！\n" NOR;
		msg += MAG "$p只觉得全身暖洋洋的，感到有点轻飘无力轻。\n" NOR;
		target->add_temp("apply/attack", -10);
		target->add_temp("apply/dodge", -10);
		target->add_temp("apply/defense", -10);
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方的攻击力和防御力

	出手要求：
		毒龙大法50级
		化骨绵掌40级
		内力300
HELP
	);
	return 1;
}

