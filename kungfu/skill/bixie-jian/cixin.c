// cixin.c  辟邪剑法「刺心」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「刺心」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		return notify_fail("你要使出"PNAME"，手上自然要有剑。\n");

	fskill = "kuihua-xinfa";
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
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");
	if ((int)me->query("max_neili") < 1000)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
	if ((int)me->query("neili") < 600)
		return notify_fail("你现在内力不够，没能将"PNAME"使完！\n");

	msg = HIC "突然之间，$N"HIC"一声大喝，"+weapon->name()+HIC"电闪而前，直刺$n"HIC"心口！\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		me->start_busy(2);
		me->add("neili", -500);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1);
		damage = damage + random(damage);
		target->receive_damage("qi",damage+random(damage/2),me);
		target->receive_wound("qi", damage,me);
    target->receive_damage("jing",damage/3+random(damage/3),me);
		target->receive_wound("jing", damage/3,me);
		msg += HIC "$n"HIC"大骇之下，忙伸手招架，哪里还来得及，卟的一声，剑尖已刺中$n"HIC"心口。\n"NOR;
		message_combatd(msg, me, target);
	} else
	{
		me->start_busy(2);
		me->add("neili", -300);
		msg += HIY"$n"HIY"情急智生，抬手也往$N"HIY"心口刺去，迫得$P回剑跃开。\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		施招刺对方的心口
		此招为辟邪剑法招势之最，阴险毒辣
		损伤对方气血和精气

	出手要求：
		辟邪剑法180级
		葵花心法100级
		最大内力1000
		内力600
HELP
	);
	return 1;
}

