// ding.c 全真剑-定阳针
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "定阳针"
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

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
		
	fskill = "yunv-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 &&
		  (int)me->query_skill("xiantian-qigong", 1) < 40 &&
			(int)me->query_skill("yunv-xinfa", 1) < 40 )
		return notify_fail("你的内功不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 150 )
		return notify_fail("你现在内力太弱，不能使用定阳针。\n");

	msg = HIC "$N左手捏着剑诀，右足踏开一招“定阳针”向上斜刺，"
	     +weapon->name()+HIC"锵然跃出，倏的化作几点星光，射向$n！\n"NOR;
// "$N脚下左弓右箭，神气完足如雷霆五岳，一式「定阳针」斜斜刺出。\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(2);
		damage = (int)me->query_skill("sword", 1) + (int)me->query_skill("force",1);
		damage = damage/2 + random(damage/2);

		target->receive_damage("qi", damage,me);
		target->start_busy(4);
		me->add("neili", -100);

		msg += HIR"$n看到$N这气拔千钧的一击，竟不知如何招架！\n"NOR;

	}
	else
	{
		me->start_busy(3);
		msg += CYN"可是$p看破了$P的企图，斜跃避开。\n"NOR;
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
		损伤对方气血
		迟滞对方出手

	出手要求：
		先天气功或玉女心法40级
		全真剑法40级
		内力150
HELP
	);
	return 1;
}

