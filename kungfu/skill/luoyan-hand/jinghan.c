// Last Modified by ahda on Aug.30 2001
// jinghan.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "雁阵惊寒"
int perform(object me, object target)
{
	string msg;
	int skill, damage, plvl;
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

	fskill = "huiyan-xinfa";
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

	msg = HIC"渔舟唱晚，响穷彭蠡之滨；雁阵惊寒，声断衡阳之浦。"HIM"
$N"HIM"使出大落雁手的绝技「雁阵惊寒」，乘$n"HIM"劲力的空隙蓦地拍向$n"HIM"的全身要穴！\n"NOR;

	message_combatd(msg, me, target);
	plvl = target->query_skill("parry",1),
	skill = me->query_skill(sskill,1);
	me->start_busy(2);
	me->add("neili", -100);
	if( random(me->query("combat_exp")*(skill/30+1)) >
		(int)target->query("combat_exp")*(plvl/50+1)) 
	{
		msg = HIW"$n被$N狂风暴雨般的双掌拍中要穴，立时真气大散！\n"NOR;
		damage =80+random((int)me->query("str")*(int)me->query_skill(bskill) /10);
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
		回雁心法50级
		大落雁手30级
		内力修为300
		内力200
HELP
	);
	return 1;
}

