// xian.c  云龙三现
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「云龙三现」"
int perform(object me, object target)
{
	object weapon;
	int damage;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "yunlong-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不够高，不能用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「云龙三现」。\n");

	msg = CYN "$N微微一笑，猛吸一口气，欲使出以气驭剑绝技攻击$n。\n"NOR;


	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill, 1) / 30 + 1);

		damage = (int)me->query_skill("force", 1);
		damage +=  2 * (int)me->query_skill("sword", 1);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -damage/2);
		msg += HIY "只见$N手中剑光幻作一条金龙，腾空而起，倏的罩向$n"HIY"，$n"HIY"只觉一股大力铺天盖地般压来，登时眼前一花，两耳轰鸣，哇的喷出一口"HIR"鲜血！！\n"NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN"可是$p猛地向后一跃，跳出了$P的攻击范围。\n"NOR;
		me->add("neili", -100);
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
		损伤对方气血

	出手要求：
		云龙神功50级
		云龙剑法50级
		内力300
HELP
	);
	return 1;
}

