// cuixin.c 摧心诀 
// Last Modified by winder on Aug. 10 2000

#include <ansi.h>
#define PNAME "「摧心诀」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
	object weapon;
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

//	if (me->query_temp("weapon") )
//		return notify_fail(PNAME"开始时不能拿着兵器！\n");

	//兵器空手均可

	fskill = "qingming-xuangong";
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
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");
	if ((int)me->query("neili")<400 || (int)me->query("max_neili")<400)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
	msg = HIG "$N"HIG"猛地一个侧身一闪，转到$n"HIG"身后，右掌往$n"HIG"后心印了下去，\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)me->query_skill(bskill, 1) * 2;// if 300 strike
		damage = damage + random(damage);  //  damage 平均 900
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage*2/3,me);
		msg +=HIR"$n"HIR"疾忙转身，却已不及，后心一震只觉得喉头一甜一条血丝从嘴角挂了下来！\n"NOR;
		me->add("neili", -damage/5);
	} else
	{
		me->start_busy(2);
		msg += HIY"可是$p也随着转身，避开了后心要害。\n"NOR;
		me->add("neili", -50);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
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
		青冥玄功80级
		摧心掌100级
		内力400
HELP
	);
	return 1;
}

