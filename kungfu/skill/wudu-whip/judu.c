//五毒鞭法  聚毒

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "聚毒"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int lvl ;
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
		(string)weapon->query("skill_type") != "whip")
		return notify_fail("你使用的武器不对。\n");

	fskill = "wudu-shengong";
	bskill = "whip";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"功力太浅，无法"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"功力太浅，无法"+PNAME+"。\n");

	if( (int)me->query("neili") < 250)
		return notify_fail("你的内力不足，无法聚毒！\n");

	me->add("neili", -200);

	if( target->is_busy() )
		return notify_fail(target->name() +"已经手忙脚乱了，不需要在用毒了。\n");

	lvl = me->query_skill(bskill, 1);
	msg = BLU"$N"BLU"默运内力，将毒气运于鞭上，只见一股蓝色的雾气罩住了长鞭。\n";
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 && random(lvl) > 20 )
	{
		msg += "$p措不及防，不由身染毒气。\n" NOR;
		target->receive_damage("qi", lvl,me);
		target->receive_wound("qi",15 + random(10),me);
		target->receive_wound("jing", 10,me);
		target->apply_condition("snake_poison", random(lvl/10) + 1 + target->query_condition("snake_poison"));
		me->start_busy(1);
		target->start_busy(1 + random(2));
	}
	else
	{
		msg += HIY"可是$p看出了$P的毒计，立刻屏住呼吸，没有中毒。\n"NOR;
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
		伤敌气血，使敌手中毒

	出手要求：
		五毒神功50级
		五毒鞭法60级
		内力250
HELP
	);
	return 1;
}

