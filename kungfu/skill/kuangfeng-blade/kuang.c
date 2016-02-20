//kuang.c -「狂风二十一式」
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「狂风二十一式」"
int perform(object me, object target)
{
	int damage;
	object weapon;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
/*  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");
*/
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你必须先去找一把刀！\n");

	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}


	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("你的内力不够。\n");

	msg = HIC"$N"HIC"淡然一笑，本就快捷绝伦的刀法骤然变得更加凌厉！就在这一瞬之间，"+ "$N已劈出二十一刀！刀夹杂着风，风里含着刀影！$n"HIC"只觉得心跳都停止了！\n"NOR;
	me->start_busy(2);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		damage = random(me->query_skill(bskill, 1) * 2);
		me->add("neili", -300);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		msg += RED "只见$n"HIC"已被$N"HIC"切得体无完肤，血如箭般由全身喷射而出！\n"NOR;
	} else {
		msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
	}
	message_combatd(msg, me, target);
	if(userp(target)) target->fight_ob(me);
	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血

	出手要求：
		狂风刀法70级
		内力400
HELP
	);
	return 1;
}

