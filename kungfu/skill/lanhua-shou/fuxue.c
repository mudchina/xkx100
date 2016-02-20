// fuxue.c 兰花拂穴手 「兰花拂穴」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「兰花拂穴」"
int perform(object me, object target)
{
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
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");
		
  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	// 兵器空手均可
	
	fskill = "bibo-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"的功力不够不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，目前还不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，目前还不能使用用"+PNAME+"。\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你内力现在不够，不能使用拈花拂穴！\n");

	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够,不能使用这一绝技!\n");
		
	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	msg = HIB"$N右手反手伸出，三个指头婉转如一朵盛开的兰花，轻盈点向了$n"HIB"的胁下要穴, 使$n动弹不得。\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg +=HIY"$p不思避闪，反而抢身迎上，任$P一指点在要穴上，行动却丝毫不为之受阻。\n"NOR;
			me->start_busy(4);
			me->add("neili", -100);
		} else {
			msg += HIB"结果$p被$P点个正着，顿时手足无措，呆立当地！ \n"NOR;
			target->start_busy( random((int)me->query_skill("hand", 1) / 20 ));
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIY "可是$p看破了$P的企图，轻轻一跃，跳了开去。\n" NOR;
		me->start_busy(4);
		if(!target->is_fighting(me) &&
			target->query("owner") &&
			me->query("id") == target->query("owner"))
		target->fight_ob(me);
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
		迟滞对方出手

	出手要求：
		碧波神功100级
		基本手法120级
		兰花拂穴手120级
		后天身法25
		内力500
HELP
	);
	return 1;
}

