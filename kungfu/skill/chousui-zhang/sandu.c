// sandu.c 抽髓掌散毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "散毒"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
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
	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || target == me ||	
//	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
  	return notify_fail("你要对谁散毒？\n");

	if( !(int)me->query_condition("poison_sandu"))
		return notify_fail("你现在没毒可散。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人！\n");

	if( !userp(target) || wizardp(target) )
		return notify_fail("散毒只能对玩家使用。\n");
		
	// 兵器空手均可

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/2 )
		return notify_fail("对这人散毒是没用的。\n");

	if( (int)me->query_skill("huagong-dafa", 1) < 40 )
		return notify_fail("你的化功大法不够娴熟，不能散毒。\n");

	if( (int)me->query_skill("chousui-zhang", 1) < 40 )
		return notify_fail("你的抽髓掌不够娴熟，不能散毒。\n");

	msg = GRN "只听得$N"GRN"的骨节格格作响，$N的手猛地长了半尺，居然一把抓住$n"GRN"手
腕，将毒质运于手心，源源不断传入$n"GRN"体内。\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("chousui-zhang",1)) > random(target->query_skill("dodge") ) )
	{
		msg += CYN "结果$p无力挣扎，$P的本身阴毒不断散入$n体内！\n" NOR;
		target->receive_damage("qi",20,me);
		target->receive_wound("qi",15 + random(10),me);
		target->apply_condition("poison_sandu", 1000);
		me->clear_condition("poison_sandu");
		if (!target->is_busy())
		target->start_busy(1 + random(2));
	} else {
		msg += "可是$p急提内力奋力一震，将$N的手震了开去。\n" NOR;
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
		练基本毒技到一定水准毒将反噬致死，必须散毒
		被散毒者必须是玩家
		被散毒者死

	出手要求：
		化功大法40级
		抽髓掌40级
HELP
	);
	return 1;
}

