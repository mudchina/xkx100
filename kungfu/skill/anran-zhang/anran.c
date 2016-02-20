// anran.c 黯然神伤
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「"+BBLU"黯然神伤"NOR +"」"

int perform(object me, object target)
{
	int damage;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用"PNAME"！\n");

	fskill = "yunv-xinfa";
	bskill = "unarmed";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 1500 )
		return notify_fail("你的内力不够。\n");
//	if (!userp(me) && me->query("id")!="yang guo")
//	  return notify_fail("只有玩家和杨过可以用黯然神伤。\n");

	msg = HIB"$N"HIB"紧闭双目，潸然泪下，神情恍惚，鹄立风中，蓦地往前直仆，掌风带起刺骨寒气，如急风骤雨般向$n"HIB"奔袭而至！ \n"NOR;
	damage = (int)me->query_skill(bskill, 1)*4; 
	damage = damage + random(damage); 
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		me->start_busy(3);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		me->add("neili", -1000);
		msg += RED"$n"RED"无处可躲，被$N"RED"双掌齐印胸口上，一口鲜血狂喷而出！\n"NOR;
	}
	else
	{
		me->start_busy(5);
		msg +=HIG"$n"HIG"大骇之下，急退数丈，才从掌风中逃身而出，只觉脸上被掌风刮得生疼。\n"NOR;
		target->receive_damage("qi",damage/10,me);
		target->receive_wound("qi",damage/20,me);
		me->add("neili", -500);
	}
	message_combatd(msg,me,target);
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
		迟滞对方出手

	出手要求：
		玉女心法150级
		黯然销魂掌150级
		内力1500
HELP
	);
	return 1;
}

