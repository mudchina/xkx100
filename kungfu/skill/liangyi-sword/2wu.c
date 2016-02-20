// 2wu.c 无声无色
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「无声无色」"
int perform(object me,object target)
{
	string msg;
	object weapon1, weapon2;
	int skill, ap, dp, neili_wound, qi_wound;
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
		
	if( !objectp(weapon1 = me->query_temp("weapon")) ||
		(string)weapon1->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
/*	if( !objectp(weapon2 = me->query_temp("secondary_weapon"))
		|| (string)weapon2->query("skill_type") != "sword")
		return notify_fail("你左手使用的武器不对。\n");
*/
	fskill = "xuantian-wuji";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，使不出"+PNAME+"。\n");

	if( me->query_skill("dodge", 1) < 80)
		return notify_fail("你基本轻功修为不够，使不出"PNAME"！\n");

	if( me->query("neili") < 250 )
		return notify_fail("你的内力不够，无法运用"PNAME"！\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够，无法运用"PNAME"！\n");
	
	skill = me->query_skill(bskill,1);

	msg = HIB "$N轻吸一口气，突然使出一招“无声无色”，手中"+weapon1->name()+HIB"灌注两道相同内劲， 但劲力恰恰相反，剑上所生的荡激之力、破空之声，一齐相互抵消，无声无息疾向$n背后刺去。\n";
	message_combatd(msg, me, target);

	ap = skill * 3;
	dp = target->query_skill("force", 1) * 2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) )
	{
		if(userp(me)) me->add("neili", -250);//400
		msg = HIR "$n突见剑刃划空之声，已无从闪避！\n" NOR;
		qi_wound = skill * 2;
		qi_wound = qi_wound + random(qi_wound);
//	target->receive_damage("qi", qi_wound/3);
		target->receive_damage("qi", qi_wound*3/4);
		target->receive_wound("qi", qi_wound/3);
		target->start_busy(2);
		me->start_busy(1+random(2));
	}
	else
	{
		me->add("neili", -100);
		msg = HIY"$n"HIY"猛地一纵而起，只听一声轻响，好险！襟袖均堪堪被$N"HIY"的剑尖划破了。\n"NOR;
		me->start_busy(2+random(1));
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
		玄天无极功100级
		两仪剑法120级
		基本剑法100级
		基本轻功80级
		内力修为500
		内力250
		
HELP
	);
	return 1;
}

