// yingzhang.c 刀影掌
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「刀影掌」"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;
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
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("「刀影掌」开始时必须拿着一把刀！\n");

	fskill = "shenyuan-gong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够！无法使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练！无法使出"+PNAME+"。\n");
	
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xingyi-strike",1) < 100 )
			return notify_fail("你的星移掌不够精通！无法使出「刀影掌」！\n");
		if( (int)me->query_skill("strike",1) < 100 )
			return notify_fail("你的基本掌法修为不够！无法使出「刀影掌」！\n");
	}

	if( (int)me->query("neili") < 100 )
		return notify_fail("你的真气不够！\n");

	msg = HIC
"$N一声长啸，手中"+weapon->query("name")+HIC"顿时泛出一股杀气，"HIR"刀影掌"HIC"！刹那间
杀气如狂风涌到,把对手罩在一圈光幕之中。 \n" NOR;
	message_combatd(msg, me, ob);
//	me->clean_up_enemy();
//	ob = me->select_opponent();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);

	me->add("neili", -50);
	me->start_busy(random(2));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手两刀

	出手要求：
		神元功100级
		基本刀法100级
		慕容刀法100级
		基本掌法100级
		星移掌100级
		内力100
HELP
	);
	return 1;
}

