// shenjian.c 桃花影里飞神剑

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h"
#define PNAME "桃花影里飞神剑"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, rand, p;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用桃花影里飞神剑！\n");

	fskill = "bibo-shengong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，无法施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，无法使用"+PNAME+"。\n");

	if ( (int)me->query("neili") < 120)
		return notify_fail("你的内力不够，无法使用桃花影里飞神剑。\n");

	if (!me->query_temp("murong/xingyi"))
	{
		if (me->query_skill_prepared("strike") != "luoying-zhang" ||
			me->query_skill_mapped("strike") != "luoying-zhang")
			return notify_fail("你现在无法使用桃花影里飞神剑进行攻击！\n");
	}
	
	msg = CYN "\n$N双掌竖起，默运碧海潮生功，掌缘便似剑锋一样发出丝丝的"GRN"剑气"CYN"，分别从左右两边斩向$n！\n"NOR;
	rand = random(me->query("combat_exp"));
	if( rand > (int)target->query("combat_exp")/4 )
	{
		me->add("neili", -100);
		me->start_busy(2);
		damage = (int)me->query_skill(bskill, 1)*3/2;
		damage += random(damage);
//		if (damage > target->query("neili") / 8)
//			damage -= target->query("neili") / 15;
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "劈伤");
		msg += "( $n" + eff_status_msg(p) + " )\n";
	}
	else
	{
		me->add("neili", -50);
		me->start_busy(3);
		msg += HIY"$n大吃一惊，退步抽身，万分惊险中堪堪躲过了这招，早已吓出了一身冷汗！\n" NOR;
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
		损伤对手气血

	出手要求：
		落英神剑掌80级
		碧波神功80级
		内力120
HELP
	);
	return 1;
}

