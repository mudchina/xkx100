//lianhuan.c 连环 perform
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "绝命连环腿"
int perform(object me, object target)
{
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
		
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正晕头转向，乘机进攻吧ⅵ\n");

		//兵器空手均可使用

	fskill = "dulong-dafa";
	bskill = "leg";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能运"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 40 )
		return notify_fail(PNAME"需要精湛的"+to_chinese(bskill)+"配合，方能有效施展。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不足，还不会使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("strike") != "huagu-mianzhang" )
			return notify_fail("你所用的并非化骨绵掌，不能与绝命连环腿配合施展！\n");
		if( me->query_skill_prepared("strike") != "huagu-mianzhang" )
			return notify_fail("你所备的并非化骨绵掌，不能与绝命连环腿配合施展！\n");
	}
	if( me->query("neili") <= 300 )
		return notify_fail("你的内力不够使用连环决！\n");

	msg = HIY "\n 突然间$N"HIY"身形腾空而起，凌空向$n"HIY"奋力连踢几腿！\n" NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") /2)
	{

		target->start_busy((int)me->query_skill(bskill, 1) / 20);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
		me->add("neili", -damage/10);
		if( damage < 40 )
			msg += HIY"结果$n"HIY"被$N"HIY"的连环腿踢得晕头转向！ⅵ\n" NOR;
		else msg += HIR"结果$n"HIY"被$N"HIY"的连环腿踢中要害，「哇！」的一口鲜血喷涌而出！\n"NOR;
	}
	else
	{
		msg += "可是$p看破了$P的企图，巧妙得躲了开去。\n" NOR;
		me->start_busy(1 + random(3));
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

	出手要求：
		毒龙大法60级
		基本腿法40级
		绝命腿40级
		内力300
		互备化骨绵掌
HELP
	);
	return 1;
}

