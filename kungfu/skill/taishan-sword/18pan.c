// Last Modified by winder on Aug. 25 2001
// 18pan.c 泰山十八盘 

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「泰山十八盘」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, neili_wound, qi_wound;
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

	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，使不出"+PNAME+"。\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法运用泰山十八盘！\n");

	if( me->query("max_neili") < 400 )
		return notify_fail("你的内力修为不够，无法运用泰山十八盘！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"已经自顾不暇了，放胆攻击吧！\n");

	skill = me->query_skill(bskill,1);
	msg = CYN "$N使出泰山十八盘剑法之缠剑式，一把剑闪出十八道剑影！\n";
	me->start_busy(1);
	me->add("neili",-100);
	if( random(me->query("combat_exp") + skill*1000) > (int)target->query("combat_exp")/3 )
	{
		msg += HIY"结果$n被缠个动弹不得！\n" NOR;
		target->start_busy( skill / 40 + 2);
	} else
	{
		msg += HIC"可是$n看破了$N的剑招，一拧身跃出了剑影。\n" NOR;
		msg += HIY"$N却一下失去平衡，反陷入了被动。\n" NOR;
		me->start_busy(3);
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
		迟滞对手出招

	出手要求：
		磐石神功70级
		泰山剑法80级
		内力修为400
		内力300
HELP
	);
	return 1;
}

