// bx_arrow.c 碧血箭
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;

int exert(object me, object target)
{
	string msg;
	int success, ap, dp;


  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/bx_arrow") &&
  !me->query("can_perform/wudu-shengong/bx_arrow") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("碧血箭只能在战斗中使用。\n");
	if( !userp(me))
		return notify_fail("只有玩家才能玩命。\n");

	if((int)me->query("max_neili") < 400 )
		return notify_fail("你的内力不够，不能有效施展碧血箭！\n");

	if((int)me->query_skill("force",1) < 50 ||
		(int)me->query_skill("wudu-shengong",1) < 50 )
		return notify_fail("你的内功修为不够，不能有效施展碧血箭！\n");

	if((int)me->query("combat_exp") < (int)target->query("combat_exp")/10)
		return notify_fail("对方武功强你十倍，不会有用的，还是快跑吧！\n");

	message_combatd( HIC
 "$N双目血红，披头散发，仰天发出一声悲啸！\n\n$N把心一横，在自己舌尖狠命一咬，将毕生功力化做一道奇毒血箭向$n喷了过去！\n" NOR,me,target);

	success = 1;
	ap = me->query_skill("force",1)+me->query_skill("wudu-shengong",1);
	ap = ap /2 ;
	ap = ap * ap * ap/10;
	ap = ap+(int)me->query("combat_exp");
//	ap = ap * ap;
	dp = target->query("combat_exp");
//	dp = dp * dp;
	if( random(ap+dp) < random(dp) ) success = 0;

	ap = (int)me->query("max_neili");
	dp = (int)target->query("max_neili");
	if( ap < random(dp) ) success = 0;

	if(success == 1 )
	{
		message_combatd(HIR"结果$n促不及防被血箭射个正着，顿时发出一声惨叫！$N见状哈哈大笑一声，眼前一黑倒在地上。\n" NOR,me,target);

		target->kill_ob(me);
		me->kill_ob(target);
		me->add("max_neili", -50);
		me->save();

		target->receive_wound("qi", (int)target->query("max_qi")+1, me);
		target->receive_wound("jing", (int)target->query("max_jing")+1,me);
		COMBAT_D->report_status(target);

		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);
	}
	else {
		message_combatd(HIR"但是血箭被$n内力反震，化做一蓬血雾四散飘去！\n$N一声惨笑，长叹一声，眼前一黑倒在地上。\n" NOR,me,target);
		target->kill_ob(me);
		me->kill_ob(target);

		me->add("max_neili", -30);
		me->save();

		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);
	}

	return 1;
}

int help(object me)
{
	write(WHT"\n五毒神功之碧血箭"NOR"\n");
	write(@HELP

	使用功效：
		赔上自己一条命，和对方拼命

	出手要求：
		五毒神功50级
		基本内功50级
		内力400
		对方经验不超过你的十倍
HELP
	);
	return 1;
}

