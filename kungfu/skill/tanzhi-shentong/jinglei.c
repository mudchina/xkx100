// jinglei.c 弹指惊雷
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「弹指惊雷」"
int perform(object me,object target)
{
	string msg;
	object weapon2 ;
	int skill, dp, wound;
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

	if( me->query_temp("weapon"))
		return notify_fail("你使用了武器。\n");

	fskill = "bibo-shengong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"未到火候, 不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使用"+PNAME+"。\n");

	if( me->query("neili") < 150 )
		return notify_fail("你的内力不够，无法运用「弹指惊雷」！\n");
 
	skill = me->query_skill(bskill, 1);
	msg = HIC "$N"HIC"使出弹指神通之「弹指惊雷」, 顿时眼内精光暴射，\n" NOR;
	message_combatd(msg, me, target);
 
	dp = target->query("combat_exp")/4;
	if( dp < 1 ) dp = 1;
	if( random(me->query("combat_exp")) > dp)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIM "$n微微一笑，抢身而上，全然不顾$N的攻势，$N一指点在$n的气海穴上，$n似乎毫无知觉，反而痛下杀手，连连出招。\n"NOR;
			me->start_busy(random(5) + 1);
			me->add("neili", -150);
		} else {
			if(userp(me)) me->add("neili",-150);
			msg =HIC"$n"HIC"只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n"NOR ;
			if ( objectp(weapon2 = target->query_temp("weapon")))
			{
				msg += HIC"同时手腕一麻，手中";
				msg += weapon2->name();
				msg += HIC"脱手而出！\n" NOR;
				weapon2->move(environment(me));
			}
			wound = skill + random(400);
			if((int)target->query("neili") < wound)
				wound = target->query("neili");
			target->add("neili", -wound);
			target->receive_damage("jing", wound/2 + random(100),me);
			target->receive_wound("jing", wound/2,me);
			if (!target->is_busy())
			target->start_busy(5);
			me->start_busy(2);
		}
	}
	else
	{
		msg ="可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。\n"NOR;
		me->start_busy(3);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		减损对方内力
		击落对方兵刃

	出手要求：
		碧波神功100级
		弹指神通120级
		内力150
HELP
	);
	return 1;
}

