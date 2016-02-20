// menda.c  「绝棍闷打」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「"+HIC"绝"NOR+HIG"棍"NOR+HIY"闷"NOR+HIR"打"NOR+"」"
int perform(object me, object target)
{
	int damage;
	string msg;
	int flag;
	object weapon;
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

		if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(bskill, 1) < 188 )
		return notify_fail("你的"+to_chinese(fskill)+"太菜，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 188 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力修为还不够高。\n");

	msg = HIW "$N突然反身疾退，$n"HIW"正疑惑发愣间，却见$N骤然转身，施展出「"+HIC"绝"NOR+HIG"棍"NOR+HIY"闷"NOR+HIR"打"NOR+"」，"+HIW"左右上下挥舞游走间，漫天杖影已压向傻不楞登的$n"HIW"。\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/5)
	{
		me->start_busy(1);
		target->start_busy(random(8));

		damage= (int)me->query_skill(bskill, 1)*5;
		damage = damage + random(damage);

		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/2);
		me->add("neili", -500);
		msg += HIR"
$n只见漫天都是杖影，根本无从招架，只有挨打的份儿，结果每一杖都被打中，直打得满头血包、浑身血条，且五脏六腑亦被重创，鲜血自嘴角汩汩流个不休，眼看就要摔晕在地！！！\n"NOR;
	} else
	{
		me->start_busy(1);
		msg += HIG"可是$p看破了$P的企图，急忙报头鼠窜般闪在了一边。\n"NOR;
	}
	message_combatd(msg, me, target);

	return 1;
}

int help(object me)
{
	write(WHT"\n绝门棍之绝棍闷打："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		迟滞对方出手

	出手要求：
		绝门棍188级
		基本杖法188级
		内力500
HELP
	);
	return 1;
}

