// Last Modified by winder on May. 15 2001
// diaoshou.c 刁手蛇形

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「刁手蛇形」"
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「刁手蛇形」！\n");

	fskill = "hamagong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，无法施展出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，无法施展出"+PNAME+"。\n");

	if ( (int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够，无法施展出「刁手蛇形」。\n");

	if ( (int)me->query("neili") < 100)
		return notify_fail("你的真气不够，无法施展出「刁手蛇形」。\n");

	extra = me->query_skill(bskill, 1);
  me->add_temp("apply/strength", extra);
	me->add_temp("apply/attack", extra);
	me->add("neili", -100);
	msg=YEL"$N拳招若隐若现，若有若无，神色怪异的缓缓又奇怪的攻向$n！\n"NOR;
	msg+=HIC"$N向$n左边打来，但突然打向$n右边！"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg=HIR"$N向$n右边打来，但突然打向$n左边！"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg=HIB"$N向$n上边打来，但突然打向$n下边！"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/strength", -extra);
	me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		大力连续出手三招

	出手要求：
		蛤蟆功100级
		蛇形刁手100级
		内力修为500
		内力100
HELP
	);
	return 1;
}

