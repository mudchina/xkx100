// suo.c 锁剑诀
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「锁剑诀」"
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, ap, dp, damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
//   !me->query("perform/"+pfname) &&
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
		(string)weapon->query("id") != "jinshe jian" ||
		weapon->query("ownmake") == 1)
		return notify_fail("你没用金蛇剑，不能使用绝招！\n");

	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有使用兵器，你用不了「锁剑诀」。\n");
		
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("dex") < 20 || me->query("str") < 20 )
		return notify_fail("你的先天膂力身法孱弱, 不能使用"PNAME"！\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法运用"PNAME"！\n");

	skill = me->query_skill(bskill, 1);

	msg = HIC "$N"HIC"手中"YEL"金蛇剑"HIC"画出一道金光，斜刺一拉，「锁剑诀」！
"YEL"金蛇剑"HIC"剑尖倒钩正好挂在$n"HIC"的"+weapon2->name()+"上。\n";
	message_combatd(msg, me, target);

	damage = 10 + random(skill / 2);
	ap = skill;
	dp = target->query_skill("dodge")/2;
	if( dp < 1 ) dp = 1;
	if( random(ap) > random(dp) )
	{
		if(userp(me)) me->add("neili",-50);
		msg = "$n顿时觉得眼前金光一闪，手腕一振，手中"+weapon2->name()+"脱手飞出！\n" NOR;
		me->start_busy(random(2));
		target->receive_damage("qi", damage,me);
		target->start_busy(2);
		weapon2->move(environment(me));
	}
	else
	{
		if(userp(me)) me->add("neili",-30);
		msg = "$n急运内力，将手中" + weapon2->name() + "斜斜顺势一送一搭，抽了回来。\n"NOR;
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		迟滞对方出手
		锁拿对方兵器

	出手要求：
		先天膂力20
		先天身法20
		金蛇剑法150级
		内力300
		使用金蛇剑
HELP
	);
	return 1;
}

