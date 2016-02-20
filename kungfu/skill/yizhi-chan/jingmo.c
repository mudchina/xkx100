// jingmo.c 一指禅 「惊魔一指」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "惊魔一指"
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
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	//兵器空手均可
	
	if((int)me->query_str() < 30)
		return notify_fail("你膂力不够，不能使用这一绝技！\n");

	fskill = "hunyuan-yiqi";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"的火候不能出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，使不出"+PNAME+"。\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够, 不能使用惊魔一指! \n");

	if( target->is_busy() )
		return notify_fail(target->name()+ "目前正自顾不暇，放胆攻击吧ⅵ\n");

	msg = HIY"$N"HIY"使出一指禅绝技「惊魔一指」，罩住了$n的全身要穴, 使$n动弹不得。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P一指正中$p的大穴，$p微微一笑，行动竟丝毫不受阻碍，$P一惊之下，呆在当场。\n"NOR;
			me->start_busy(4);
			me->add("neili", -150);
		} else {
			msg += "结果$p被$P攻了个措手不及！\n" NOR;
			target->start_busy((int)me->query_skill(bskill,1)/20+2);
			me->add("neili", -300);
		       }
	} else {
		msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
		me->add("neili", -300);
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
		混元一气功100级
		基本指法150级
		一指禅150级
		内力800
		后天膂力30
HELP
	);
	return 1;
}

