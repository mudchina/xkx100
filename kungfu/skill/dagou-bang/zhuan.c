// zhuan.c 打狗棒法「转」字诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「转」字诀"
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
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

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "stick")
		return notify_fail("你使用的武器不对。\n");

	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"不够深厚，不会使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");
	if( (int)me->query("max_neili") < 700 )
		return notify_fail("你的内力修为不够！\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");
	msg = HIY"$N"HIY"微微一笑，挥"+weapon->name()+"往$n"HIY"脸上横扫过去，势挟劲风，甚是峻急。\n";
	me->start_busy(2);
	if( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2 )
	{
		msg += HIR "$n连忙后仰相避，这麽一来，下盘扎的马步自然松了。$N"+weapon->name()+HIR"回带，使个「转」字诀，往$n脚下掠去，$n立足不稳，扑地跌倒。\n" NOR;
		if(target->query("neili") > 300) target->add("neili", -300 );
		else target->set("neili", 0 );
	} else {
		msg += HIC"可是$n"HIC"后跃一小步，$N"HIC"的"+weapon->name()+HIC"顿时落空。\n" NOR;
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
        消耗敌人的内力

	出手要求：
		混天气功150级
		打狗棒法150级
		内力修为700
		内力500
HELP
	);
	return 1;
}

