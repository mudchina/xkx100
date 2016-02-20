// diezhang.c 昆仑掌法  perform 昆山叠掌

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "「昆山叠掌」"
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
		
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能施展"PNAME"。\n");

	fskill = "xuantian-wuji";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("strike") != "kunlun-strike" || 
			me->query_skill_mapped("parry") != "kunlun-strike")
			return notify_fail("你现在无法使用「昆山叠掌」进行攻击。\n");
	}
	if( (int)me->query_str() < 26 )
		return notify_fail("你的膂力不够强，不能使用「昆山叠掌」。\n");
	arg = (int)(me->query_skill(bskill, 1) / 30);

	if( arg <= 1 )
		return notify_fail("至少要有两招才可组成"PNAME"。\n");

	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你内力修为不够，不能使用"PNAME"。\n");

	if( (int)me->query("neili", 1) < 200 )
		return notify_fail("你现在内力太弱，不能使用"PNAME"。\n");

	if( (int)me->query("neili", 1) < 100 * arg )
		return notify_fail("你现在的内力施展不了那么多招。\n");

	message_combatd(HIG"$N"HIG"深吸一口气，大喝一声，连续击出"+ chinese_number(arg) +"掌，后招推着前招，掌力叠合在一起扑向$n"HIG"！\n\n"NOR, me, target);
	if( random(me->query("combat_exp")) > target->query("combat_exp")/2 )
	{
		limbs = target->query("limbs");
		for(count = 0; count < arg; count++)
		{
			message_combatd( replace_string( SKILL_D("kunlun-strike")->query_action(me, me->query_temp("weapon"))["action"], "$l", limbs[random(sizeof(limbs))]) + "！\n\n", me, target);
			damage = damage+100+random(500);
		}
		damage = (1 + me->query("jiali")/300) * damage / 2;
	
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
		msg =HIY"\n$n"HIY"身形急速后退，顺着掌风就势一跳，躲开了这攻击。\n" NOR;
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
		昆仑掌法100级
		基本掌法100级
		玄天无极140级
		后天膂力26
		内力1500
		激发昆仑掌法为招架技能
		激发昆仑掌法为掌法技能
		指定掌法技能(prepare)
HELP
	);
	return 1;
}

