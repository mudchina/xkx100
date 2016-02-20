// Last Modified by winder on Sep. 12 2001
// zhuihun.c 一剑追魂

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "一剑追魂"
int perform(object me, object target)
{
	object weapon;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "honghua-shengong";
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
		return notify_fail("你的"+to_chinese(fskill)+"不够高，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	damage = (int)me->query_skill("force", 1);
	damage += (int)me->query_skill(bskill, 1)*3/2;

	if( (int)me->query("max_neili") < damage + 100)
		return notify_fail("你的内力修为太弱，使不出「一剑追魂」。\n");

	if( (int)me->query("neili") < damage )
		return notify_fail("你现在内力太弱，不能使用「一剑追魂」。\n");
			
	msg = CYN "$N微微一笑，猛吸一口气，飞身跃起，"+weapon->name()+CYN"如无常索命索，绞向$n。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -(damage/4));
		msg += HIR "$n只觉剑势如夜幕般铺天盖地般压来，一时间眼前一花，两耳轰鸣，无从招架！！\n"NOR;
		me->start_busy(1);
	} else 
	{
		msg += CYN"可是$p见机极快，飞身跃出了$P的剑网。\n"NOR;
		me->add("neili", -100);
		me->start_busy(1+random(1));
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
		伤害对方气血

	出手要求：
		红花神功120级
		追魂夺命剑120级
		足够的内力修为
		足够的内力
HELP
	);
	return 1;
}

