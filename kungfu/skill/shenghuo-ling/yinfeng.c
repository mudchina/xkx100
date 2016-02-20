// yinfeng.c 阴风刀
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「阴风刀」"
int perform(object me,object target)
{
	string msg;
	object weapon;
	int skill, ap, dp, damage;


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
		(string)weapon->query("id") != "shenghuo ling" ||
		weapon->query("ownmake") == 1)
		return notify_fail("你没用圣火令，不能使用绝招！\n");

	fskill = "jiuyang-shengong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使"+PNAME+"。\n");

	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够，无法使出阴风刀！\n");
 	skill = me->query_skill(bskill, 1);

	msg = CYN "$N"CYN"突然使出“阴风刀”，一股阴劲如刀、如剑、如匕、如凿，直插入
$n胸口的“玉堂穴”中, 利如钢刃。\n"NOR;

	message_combatd(msg, me, target);
	ap = me->query("combat_exp") / 2000;
	dp = target->query("combat_exp") / 3000;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili", -300);
		msg=HIG"$n霎时之间闭气窒息，全身动弹不得。\n"NOR;
		target->start_busy(3+random(2));
		target->receive_damage("qi", skill+random(skill));
		me->start_busy(1);
	}
	else
	{
		msg = HIY"$n一声清啸, 飞身后跃相避。气提丹田, 内力顿生。\n"NOR;
		me->start_busy(2);
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
		圣火令法120级
		九阳神功120级
		内力500
		使用圣火令
HELP
	);
	return 1;
}

