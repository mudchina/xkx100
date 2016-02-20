// Last Modified by winder on Jul. 15 2001
// chanyun.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "缠云手"
int perform(object me, object target)
{
	string msg;
	int damage, plvl, hlvl;
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
		
		//空手兵器均可
		
	fskill = "hanbing-zhenqi";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 30 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query("max_neili")< 300 )
		return notify_fail("你的内力修为不够。\n"); 

	if( (int)me->query("neili")< 200 )
		return notify_fail("你的内力不够。\n"); 

	msg = HIW"$N"HIW"使出破云手的绝技「缠云手」，双手出手鬼祟，乘$n"HIW"劲力的空隙蓦地拍向$n"HIW"的全身要穴！\n"NOR;
	message_combatd(msg, me, target);
	plvl = target->query_skill("parry",1),
	hlvl = me->query_skill(bskill,1),
	me->start_busy(2);
	me->add("neili", -100);
	if( random(me->query("combat_exp")*(hlvl/20+1)) >	(int)target->query("combat_exp")*(plvl/50+1)) 
	{
		msg = HIW"$n结果被$N狂风暴雨般的双掌拍中要穴，立时顿觉真气大散！\n"NOR;
		damage =40+random((int)me->query("str")*hlvl/10);
		message_combatd(msg, me, target);
		target->receive_damage("qi", damage,me);
		COMBAT_D->report_status(target);
		return 1;
	} else
	{
		msg = HIG "结果$p看破了$P的企图，身行后跃，并没有上当。\n" NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损害敌手气血

	出手要求：
		寒冰真气50级
		破云手30级
		内力修为300
		内力200
HELP
	);
	return 1;
}

