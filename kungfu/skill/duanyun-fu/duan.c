//duan.c 夺命三斧之「断云斩」
// Last Modified by winder on Mar. 10 2000
#include <ansi.h>
#include <combat.h>
#define PNAME "「断云斩」"
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(fskill)+"还使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 70 )
		return notify_fail("你的"+to_chinese(sskill)+"功力还使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 400 )
		return notify_fail("你的内力不够。\n");
	me->add("neili", -200);
msg = HIC"$N突然暴喝一声，将手中巨斧斜向上举起，然后在半空中划出一
道圆弧，随即径直斜下斩向$n！这一瞬间，$n只觉得呼吸都停止了！\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (!target->is_busy())
		target->start_busy( (int)me->query_skill(bskill) / 30);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage/2 + random(damage);

		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
                me->start_busy(1);
		msg += RED "只见$n被$N一斧砍中，胸前裂开一道深深的伤口，血如箭般喷射而出！\n"NOR;
	} else {
		msg += HIC "可是$p急忙抽身躲开，$P这招没有得逞。\n" NOR;
	        me->start_busy(1+random(2));
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
		损伤对方气血
		迟滞对方出手

	出手要求：
		枯荣禅功70级
		断云斧70级
		内力400
HELP
	);
	return 1;
}

