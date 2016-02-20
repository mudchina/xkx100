// throw.c 灵蛇杖法喷毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "喷毒"

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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
  	return notify_fail("你要对谁喷毒? \n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人！\n");
  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");

	fskill = "hamagong";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不能"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不能"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("你的内力不够，不能喷毒。\n");

	if( (string)weapon->query("id") != "she zhang" )
		return notify_fail("你手中没有蛇杖，不能喷毒。\n");

	me->add("neili", -200);

	msg = MAG "$N"MAG"喉间发出刺耳的格格声响，蛇杖前头的小蛇猛地扬头，一阵粉红毒雾带着甜香喷向$n"MAG"。\n";

	me->start_busy(1);

	if( random( (int)me->query_skill(bskill, 1)) >
		random(target->query_skill("dodge", 1)) )
	{
		msg += MAG "结果$p被$P杖头小蛇一口喷中！\n" NOR;
		if (target->query("neili") < me->query("neili"))
		{
			msg += MAG "$p只闻到一阵甜香，眼前就模糊起来。\n" NOR;
			target->receive_damage("qi",(int)me->query_skill("staff", 1),me);
			target->receive_wound("qi",15 + random(10),me);
			target->receive_wound("jing", 10,me);
			target->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 + target->query_condition("snake_poison"));
			target->start_busy(1 + random(2));
		}
		else
		{
			msg += CYN "$p急运内力，一口真气向蛇毒喷去，顿时蛇毒反向$P飘了回去。\n" NOR;
			msg += MAG "$P只闻到一阵甜香，眼前就模糊起来。\n" NOR;
			me->receive_damage("qi", me->query_skill(bskill, 1),target);
			me->receive_wound("qi", 15 + random(10),target);
			me->receive_wound("jing", 10,target);
			me->apply_condition("snake_poison", random(me->query_skill(bskill, 1)/10) + 1 +
			me->query_condition("snake_poison"));
			me->start_busy(1 + random(2));
		}
	} else {
		msg += CYN"可是$p急忙闪在一旁，躲了开去。\n" NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		伤害对方精气
		使对手中蛇毒
		若武功不够，可能反受其害

	出手要求：
		蛤蟆功40
		灵蛇杖法40
		手持蛇杖
		内力400
HELP
	);
	return 1;
}
