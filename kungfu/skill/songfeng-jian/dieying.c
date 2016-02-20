// dieying.c 松间蝶影
// Last Modified by sir on 4/25/2001



#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「松间蝶影」"
int perform(object me,object target)
{
	string msg;
	object weapon ;
	int skill, /*ap,*/ dp, neili_wound, qi_wound;
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

	fskill = "qingming-xuangong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法运用「松间蝶影」！\n");

	msg = HIG "$N"HIG"凝神息气，剑附内力，一式「松间蝶影」，"+weapon->name()+HIG "挽出千万朵剑花，剑影如蝶般扑向$n"HIG"。\n";
	message_combatd(msg, me, target);

	skill = me->query_skill(bskill,1);
  dp = target->query_skill("force");
	if( dp < 1 ) dp = 1;
//	if( random(skill) > dp/2 ) //相同100级就是 random(100) > 150/2  好低...
	if ( random(skill) > dp/4 ) // random(100) > 150/4  now
	{
		if(userp(me)) me->add("neili", -150);
		msg ="$n顿时觉得眼前蝶影飘飞，双耳嗡嗡内鸣，全身上下一阵刺痛如针扎一般！\n" NOR;
		qi_wound = 2 * skill;
		qi_wound = qi_wound/2 + random(qi_wound);

		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
   	me->start_busy(1+random(3));
	}
	else
	{
		me->add("neili",-50);
		msg = "可是$n宁心静气，身行虚晃，跃出剑影。\n"NOR;
		me->start_busy(1+random(3));
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
		伤敌气血并使其暂时不能动弹。

	出手要求：
		青冥玄功120级
		松风剑法150级
		内力300
HELP
	);
	return 1;
}
