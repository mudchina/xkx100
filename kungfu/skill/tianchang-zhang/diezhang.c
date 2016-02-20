// diezhang.c 天长叠掌 

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "「天长叠掌」"

int perform(object me, object target)
{
	string msg, *limbs;
	int p,count, damage = 0;
	int arg;
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
	if( me->query_temp("weapon") )
		return notify_fail("只有空手才能施展「天长叠掌」。\n");

	fskill = "baiyun-xinfa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	arg =(int)(me->query_skill(bskill, 1) / 30);

	if( arg <= 1 )
		return notify_fail("至少要有两招才可组成「天长叠掌」。\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你内力修为不够，不能使用「天长叠掌」。\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("你现在内力太弱，不能使用「天长叠掌」。\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("你现在的内力施展不了那么多招。\n");

	message_combatd(HIG"$N深吸一口气，一声娇喝，连续击出"+ chinese_number(arg) +"掌，后招推着前招，掌力叠合在一起扑向$n！\n\n"NOR, me, target);
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("tianchang-zhang")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
			damage = damage+100+random(100);
		}
		damage = (1 + me->query("jiali")/100) * damage / 2;
	
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);	
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";

		me->add("neili", -100 * arg/2);
		me->start_busy(2);
	}
	else
	{
		me->start_busy(arg/2+1);
		me->add("neili", -200);
		target->add("neili", -100);
		msg =HIY"\n$n身型急退，顺着掌风就势一跳，躲开了这攻击。\n" NOR;
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
		伤敌气血，并使敌受内伤

	出手要求：
		天长掌法100级
		基本掌法100级
		白云心法140级		
		内力1500		
HELP
	);
	return 1;
}

