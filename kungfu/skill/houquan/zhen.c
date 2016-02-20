// zhen.c 猴拳「震」字诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「震」字诀"
inherit F_SSERVER;
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
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「震」字诀！\n");		

	fskill = "yunlong-shengong";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能使用"PNAME"。\n");
			
	msg = CYN "$N"CYN"默运神功，使出猴拳「震」字诀，企图以内力震伤$n"CYN"。\n"NOR;
	me->add("neili", -50);

//	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage=me->query_skill("force",1)+me->query_skill(bskill,1);
		damage = damage/2 + random(damage/2);
		
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/3,me);
    me->add("neili", -damage/3);
		
		if( damage < 20 ) msg += HIY"结果$n受到$N的内力反震，闷哼一声。\n"NOR;
        	else if( damage < 40 ) msg += HIY"结果$n被$N以内力反震，「嘿」地一声退了两步。\n"NOR;
        	else if( damage < 80 ) msg += RED"结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIR"结果$n被$N的内力一震，眼前一黑，身子向后飞出丈许！！\n"NOR;
		
	} else 
	{
		me->start_busy(3);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
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
		迟滞对方出手

	出手要求：
		云龙神功40级
		猴拳40级
		内力100
HELP
	);
	return 1;
}

