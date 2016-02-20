// sunxin.c 损心诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「" HIR "损心诀" NOR "」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, attack_decrease;
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用「损心诀」。\n");

	fskill = "jiuyang-shengong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不足，不能随便使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"的修为不够，不能够体会"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(bskill)+"还不到家，无法体现七伤拳的"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够高！\n");

	skill = me->query_skill(bskill,1) + me->query_skill("force",1);

	msg = HIY"$N凝神定气，使出七伤拳总诀中的「" HIR "损心诀" HIY "」，双拳势如雷霆，向$n击去。\n"NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp") + skill * 500;
	dp = target->query("combat_exp") / 4;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-500);
		msg = HIG "$N连环拳势如风雷，$n"HIG"中了$N"HIG"开山裂石的一拳，顿时心神大震，不能随意出招！\n"NOR;
		attack_decrease = (int)target->query("apply/attack") ;
		if (attack_decrease > 0)
		target->add_temp("apply/attack", -attack_decrease);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		msg = HIG "只见$n"HIG"不慌不忙，轻轻一闪，躲过了$N"HIG"的必杀一击！\n"NOR;
		if(userp(me)) me->add("neili",-200);
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
		损害对手的攻击能力

	出手要求：
		九阳神功60级
		基本拳法60级
		七伤拳60级
		内力500
HELP
	);
	return 1;
}


