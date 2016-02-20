// duanjia-sword.c 段家剑 惊天一击
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「惊天一击」"
inherit F_SSERVER;
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

	fskill = "kurong-changong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够高，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("你现在内力太弱，不能使用"PNAME"。\n");
			
	if( (int)me->query("max_neili") < 300 )
		return notify_fail("你内力修为太弱，不能使用"PNAME"。\n");
			
	msg = CYN "$N"CYN"一跃而起，手腕一抖，挽出一个美丽的剑花，飞向$n"CYN"。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		if (!target->is_busy())
		target->start_busy((int)me->query_skill("sword")/30);
		
		damage = me->query_skill("force",1)+me->query_skill("sword",1);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/4,me);
		me->add("neili", -damage);
		msg += HIR"只见$N人剑合一，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"可是$p猛地向边上一跃,跳出了$P的攻击范围。\n"NOR;
		me->add("neili", -100);
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
		损伤对方气血
		迟滞对方出手

	出手要求：
		枯荣禅功70级
		段家剑70级
		内力300
HELP
	);
	return 1;
}

