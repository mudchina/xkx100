// ruhe.c  岱宗如何
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「岱宗如何」"
int perform(object me,object target)
{
	string msg;
	object weapon ;
	int ap, dp, neili_wound, qi_wound;
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

	fskill = "panshi-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，使不出"+PNAME+"。\n");

	if( me->query("neili") < 250 )
		return notify_fail("你的内力不够，无法运用岱宗如何！\n");

	if( me->query("max_neili") < 500 )
		return notify_fail("你的内力修为不够，无法运用岱宗如何！\n");

	message_combatd( HIY"$N右手"+weapon->name()+HIY"斜指而下，左手五指正在屈指而数，从一数到五，握而成拳，又将拇指伸出，次而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中指，然后手中"+weapon->name()+HIY"剑光暴长，向$n疾刺而去。\n"NOR,me,target);

	me->add("neili", -250);
	me->start_call_out( (: call_other, __FILE__, "hit_him", me, target :), /*random(5)+*/3);
	me->start_busy(3);
	return 1;
}
void hit_him(object me, object target)
{
	string msg;
	int skill = me->query_skill("sword", 1);

	if(me->is_fighting(target) && target->is_fighting(me) &&
		environment(me) == environment(target))
	{
		msg = HIY"$N使出泰山剑法中一击必中的"+HIR "岱宗如何" +HIY"，无论$n窜高跃低，变换方位，均无从闪避，只觉得眼前一花，一股"HIR"血箭"HIY"喷涌而出。\n" NOR;
		message_combatd(msg, me, target);
		target->receive_damage("qi",skill*2+me->query_skill("force",1),me);
		target->receive_wound("qi",skill+me->query_skill("force",1),me);
	}
	return ;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血，每出必中

	出手要求：
		磐石神功150级
		泰山剑法180级
		基本剑法120级
		内力修为500
		内力250
HELP
	);
	return 1;
}

