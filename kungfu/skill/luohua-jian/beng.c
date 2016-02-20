// Last Modified by winder on Sep. 12 2001
// beng.c 崩字诀

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「崩」字诀"
int perform(object me,object target)
{
	object weapon, weapon2;
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

	if(!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	fskill = "honghua-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的内力修为不够！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if(!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有用兵刃，你用不了「崩」字诀。\n");

	msg = HIY "$N稳住身形，吐气开声，剑柄一横，使出落花剑“崩”字诀！\n"NOR;
	message_combatd(msg, me);
	
	if ( random(me->query("str")) > (int)target->query("str")/2 &&
		me->query("combat_exp") > (int)target->query("combat_exp")/4*3 )
	{
		msg = HIY"$n"HIY"只觉得虎口剧痛，手中";
		msg += weapon2->name();
		msg += HIY"顿时把捏不住脱手飞了出去！\n" NOR;
		me->add("neili", -150);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		me->add("neili",-50);
		msg = HIY"可是$n"HIY"看出了$N"HIY"的企图，立刻手上加劲，将" + weapon2->name() + HIY"奋力向外一挡，\n双方兵刃的碰在一起,“铛”的发出一声巨响。\n"NOR;
		me->start_busy(2);
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
		击落对方兵刃

	出手要求：
		红花神功80级
		落花十三剑80级
		内力修为600
		内力500
HELP
	);
	return 1;
}

