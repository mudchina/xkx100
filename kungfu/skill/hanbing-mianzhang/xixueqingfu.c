// xixueqingfu.c 吸血青蝠
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「吸血青蝠」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
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

//	if (me->query("family/family_name") != "明教")
//		return notify_fail("非明教弟子，无法无法运用「吸血青蝠」。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你使用了武器。\n");

	fskill = "jiuyang-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不够，无法运用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"不够，无法运用"+PNAME+"。\n");

	if( me->query("neili") < 200 )
		return notify_fail("你的内力不够，无法运用「吸血青蝠」！\n");

	msg = HIC "$N"HIC"突然如同「吸血青蝠」，欺近$n"HIC"的身前，张嘴便向$n"HIC"的咽喉咬去。\n"NOR;
	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

		msg = HIG "$n"HIG"只觉得咽喉一阵剧痛，$N"HIG"正在狂吸$n"HIG"的鲜血！\n"NOR;
		neili_wound = 100 + random(skill);

		qi_wound = neili_wound * 2;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_wound("qi", qi_wound,me);

		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		target->add("neili", -neili_wound);

		target->start_busy(2);
		me->start_busy(random(2));
	}
	else
	{
		msg = HIG "只见$n"HIG"不慌不忙，轻轻一闪，躲过了$N"HIG"的利齿！\n"NOR;
		if(userp(me)) me->add("neili",-100);
		me->start_busy(4);
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
		减低对方内力

	出手要求：
		九阳神功50级
		寒冰绵掌60级
		基本轻功150级
		内力200
HELP
	);
	return 1;
}

