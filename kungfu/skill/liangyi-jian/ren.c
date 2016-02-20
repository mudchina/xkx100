// ren.c  两仪剑法「天地同仁」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「天地同仁」"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你没装备剑就想使"PNAME"？\n"NOR);

	fskill = "taiji-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(fskill)+"的火候不够，无法使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"未娴熟，使不出"+PNAME+"。\n");

if ((int)me->query("max_neili")<400)
		return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);

	if ((int)me->query("neili")<200)
		return notify_fail("你内力不足，没能将"PNAME"使完！\n");

	msg = HIC"$N手中"+weapon->query("name")+HIC"剑芒跃动，剑光暴长，剑尖颤动似乎分左右刺向$n，
$n看到剑光偏左，疾侧身右转，但只这一刹，剑光刹时袭向右首！\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
	random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		if (!target->is_busy())
		target->start_busy(random(3));
		damage = me->query_skill("sword", 1) * 2;
		damage = damage/2 + random(damage);
		target->receive_damage("qi", damage/2,me);
		target->receive_wound("qi", damage/3,me);
		msg +=HIC"$n疾忙左转，却发现$N的"+weapon->query("name")+HIC"根本没有右偏，「天地同仁」！
在$n左胸留下一个"HIR"血洞"HIC"！$n一低头，便看到胸口鲜血涌泉喷出！\n"NOR;
		me->add("neili", -damage/5);
	} else
	{
		me->start_busy(2);
		msg +=HIY"可是$p轻轻一笑，侧身右转，果然$P的剑式突然左展，在$p身前\n划过，仅差半寸。一根毫毛都没伤到。\n"NOR;
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
		损伤对方气血
		迟滞对方出手

	出手要求：
		太极神功90级
		两仪剑法60级
		内力400
HELP
	);
	return 1;
}

