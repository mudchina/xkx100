// zhangdao.c 铁掌掌法 「掌刀」
// Last Modified by winder on Aug. 28 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「掌刀」"
void remove_effect(object me, int amount);

int perform(object me, object target)
{
	int skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
*/	
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「掌刀」！\n");
		
	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等级还不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，使不出"+PNAME+"。\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("你所使用的内功不对。\n");

	if (!me->query_temp("murong/xingyi"))
	{
		if (me->query_skill_prepared("strike") != "tiezhang-zhangfa" ||
			me->query_skill_mapped("strike")!= "tiezhang-zhangfa" ||
			me->query_skill_mapped("parry") != "tiezhang-zhangfa")
			return notify_fail("你现在无法使用「掌刀」！\n");
	}
	if((int)me->query_str() < 30 )
		return notify_fail("你的膂力还不够强劲，使不出「掌刀」来。\n");

	if((int)me->query("neili") < 500 ) 
		return notify_fail("你的内力不够。\n");

	if((int)me->query_temp("tzzf") ) 
		return notify_fail("你已经在掌刀的运功中。\n");

	skill = me->query_skill(bskill, 1) / 2;
	me->add("neili", -(me->query_skill(bskill)+100));
	message_combatd(YEL"$N突然面色苍白，双手颤抖，随即两眼神光一闪，一双手掌颜色变的雪白，发出一种奇怪的光芒！\n" NOR, me, target);
	me->set_temp("tzzf", 1);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", skill);
	me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void remove_effect(object me, int amount)
{	
	me->delete_temp("tzzf");
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount);
	message_combatd(YEL"\n$N掌刀运功完毕，双手逐渐恢复了原状。\n"NOR, me);
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增强出手攻击力

	出手要求：
		归元吐纳法120级
		铁掌掌法120级
		基本掌法140级
		后天膂力30级
		内力500
HELP
	);
	return 1;
}

