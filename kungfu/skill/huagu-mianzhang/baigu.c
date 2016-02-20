// baigu.c 白骨森然 
// Last Modified by sir on 4/27/2001

#include <ansi.h>
#define PNAME "「白骨森然」"
inherit F_SSERVER;
int perform(object me, object target)
{
	int damage;
	string msg;
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

	if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME"开始时不能拿着兵器！\n");

	fskill = "dafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if ((int)me->query("neili")<400 || (int)me->query("max_neili")<400)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);

	msg = BLU "$N"BLU"面无表情，蓦然游身而上，绕着$n"BLU"疾转数圈，猛地身形一缩，转到$n"BLU"身前，右手划出一道光圈，往$n"BLU"丹田印了下去！\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = (int)target->query("neili")/2;
		if (damage < 300) damage = 300;
		if (damage > target->query("neili")) damage = target->query("neili");
		target->add("neili",-damage);		
		msg +=CYN"$n"CYN"匆忙闪身，却已不及，只觉浑身真气难聚，人如软泥般向后瘫倒！\n"NOR;
		me->add("neili", -damage/4);
	} else
	{
		me->start_busy(2);
		msg += HIY"可是$p也随着纵身斜跃，避开了丹田要害。\n"NOR;
		me->add("neili",-100);
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
		损伤对方内力
		迟滞对方出手

	出手要求：
		毒龙大法100级
		化骨绵掌150级
		内力400
HELP
	);
	return 1;
}

