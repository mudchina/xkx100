// xunlei.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
#include <combat.h>
#define PNAME "「迅雷」"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int i, j, z;
	object weapon;
	int flag;
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须在使用剑时才能使出"PNAME"！\n");

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

	if( (int)me->query_skill(fskill, 1) < 160 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 160 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if( (int)me->query_str() < 32)
		return notify_fail("你的膂力还不够，使不出「迅雷」。\n");

	if( (int)me->query_dex() < 30)
		return notify_fail("你的身法还不够，使不出「迅雷」。\n");

	if( (int)me->query("max_neili") < 1800 )
		return notify_fail("你现在内力太弱，使不出「迅雷」。\n");

	if( (int)me->query("neili") < 900 )
		return notify_fail("你现在真气太弱，使不出「迅雷」。\n"); 

	j = me->query_skill(bskill, 1);
	z = me->query_skill("force", 1);
 
	me->add_temp("apply/damage", z/8);
	me->add_temp("apply/dodge",-j/10);
	me->add_temp("apply/attack", j/6); 
 
	msg = BLU"\n$N将手中的"+weapon->name()+BLU"缓缓向$n一压，忽然剑光一闪， 一剑幻为四剑，宛如奔雷掣电攻向$n！\n\n"NOR;
	message_combatd(msg, me, target);
	for (i=0;i<4;i++)
	{
		if (flag == 1) target =  offensive_target(me);
		if (!objectp(target)) break;
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	me->add("neili",-j*2);
	me->add_temp("apply/damage", -z/8);
	me->add_temp("apply/dodge", j/10);
	me->add_temp("apply/attack", -j/6);

	me->start_busy(random(3)+1);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续重剑出击

	出手要求：
		玉女心法160级
		玄铁剑法160级
		内力修为1800
		内力900
		后天膂力32
		后天身法30
HELP
	);
	return 1;
}

