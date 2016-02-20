// luoyan.c 回风落雁
// Last Modified by ahda on Aug.31 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「回风落雁」"

int perform(object me,object target)
{
	string msg;
	object weapon;
	int ap,dp,qi_wound;
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
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "huiyan-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 250 )
		return notify_fail("你的内力不够，无法运用"PNAME"！\n");

	msg = HIC"$N"HIC"一声长啸，剑附内力，一式「回风落雁」，"+weapon->name()+HIC"疾如闪电，瞬间罩住$n"HIC"全身各处大穴。\n剑影中，只见$N微一侧身，右手翻转，寒光中"+weapon->name()+"突然自上而下刺出，直指$n"HIC"身上要害 \n" NOR;
	message_combatd(msg, me, target);

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 3;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili",-200);
		msg = HIY"$n顿时觉得眼前金光乱闪，双耳嗡嗡内鸣，不知那里一阵刺痛如针扎一般！\n" NOR;
		qi_wound = (int)me->query_skill(bskill,1) * 2;
		qi_wound = qi_wound/2 + random(qi_wound);

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
		me->start_busy(random(3));
	}
	else
	{
		if(userp(me)) me->add("neili",-100);
		msg =HIW"可是$n宁神静气，随手将$N的招数撇在一边。\n"NOR;
		me->start_busy(random(3));
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
		损伤对方气血

	出手要求：
		回雁心法80级
		衡山剑法90级
		内力250
HELP
	);
	return 1;
}

