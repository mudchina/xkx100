// Last Modified by winder on May. 15 2001
// saoye.c 狂风扫落叶
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「狂风扫落叶」"
int perform(object me, object target)
{
	string msg;
	string *staff_msg = ({
	YEL"$N身形加快，所到之处，狂风四起！" NOR,
	YEL"$N突如起来的从狂风中闪出，对着$n胸前就是一杖！" NOR,
	YEL"$N御杖回身，立于$n身侧，反手一劈！" NOR,
	YEL"$N借力打力，一个纵身，居高临下，当头又是一杖！" NOR,
	YEL"人在半空，$N化虚为掌，化实为杖，朝$n点刺过去！" NOR,
	YEL"$N持杖乱舞，密不透风，使$n渐渐感到透不过气来！" NOR,
	YEL"$N见有机可乘，一杖接着一杖，招招致命！" NOR,
	YEL"$N聚起天地之灵气，手中杖卷起千层大浪朝$n挥去！" NOR,
	});
	int extra,attack_time,i;
	object weapon,ob;
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
		(string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不对。\n");
		
	fskill = "hamagong";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 170 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不够，无法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 1200 )
		return notify_fail("你的真气不够！\n");

	if( !userp(me))
		return notify_fail("只有玩家才能扫落叶。\n");

	extra = me->query_skill("staff", 1);
	extra = extra / 3;

	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

	msg = HIY"$N跳出数丈外，突然一声暴喝：“------ 狂 ----- 风 ----- 扫 ----- 落 ----- 叶 ----- ！！！”" NOR;
	message_combatd(msg, me, target);		
	
	attack_time = 3 + random(6);
	for(i = 0; i < attack_time; i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		msg=staff_msg[i];
		message_combatd(msg, me, target);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
	}
	me->add("neili", -90*i);
	me->start_busy(2+random(4));		  
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra*2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手八杖

	出手要求：
		蛤蟆功180级
		灵蛇杖法170级
		内力1200
HELP
	);
	return 1;
}

