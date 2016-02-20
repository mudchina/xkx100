// duo.c 空手入白刃
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <xiaoyao.h> 

inherit F_SSERVER;
#define PNAME "空手入白刃"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, dp, damage;
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

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手。\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有兵刃，你不用担心。\n");

	fskill = "beiming-shengong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够, 不能"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够, 不能"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(bskill)+"火候不够, 不能"+PNAME+"。\n");

	if( me->query("neili") < 50 )
		return notify_fail("你的内力不够，无法空手入白刃！\n");

	skill = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"凝神闭息，打算施展空手入白刃的绝技。\n";
	message_combatd(msg, me);
 
	dp = target->query_skill("parry", 1);
	if( dp < 1 )
		dp = 1;
	if (fam_type(me)=="xiaoyao") dp /= 2;
	if( random(skill) > dp *4/5)
	{
		me->add("neili",-50);
		msg ="$N使出空手入白刃的绝招, $n顿时觉得眼前一花，手腕一麻，手中兵刃脱手而出！\n" NOR;
		target->start_busy(2);
		weapon2->move(me);
		if (weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "只听一声脆响！兵刃落地。\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = "可是$n的看破了$N的企图，立刻采取守势，使$N没能夺下兵刃。\n"NOR;
		me->start_busy(4);
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
		劫夺对方兵刃

	出手要求：
		北冥神功50级
		天山折梅手50级
		基本手法50级
		内力50
HELP
	);
	return 1;
}

