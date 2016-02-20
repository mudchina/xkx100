// fugu.c 金蛇游身掌-附骨缠身
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「附骨缠身」"
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int i;
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
		
	if( me->query_temp("weapon"))
		return notify_fail("你不是空手，不能使用"PNAME"。\n");

	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用附骨缠身。\n");

	msg = HIC "$N大喝一声，缠身而上左手一探刁住$n"HIC"手腕，右掌猛下杀手！\n"NOR;
	message_combatd(msg, me, target);


	if(random(me->query_skill(bskill,1))>target->query_skill("dodge",1)/2)
	{
		for (i=0;i<3;i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (objectp(target))
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		}
		me->add("neili", -50);
		me->start_busy(2+random(2));
		msg=HIR"结果$n被$N的左手所制，在「附骨缠身」下，竟然无法还手！\n"NOR;
	}
	else
	{
		me->start_busy(3);
		msg=CYN"可是$p识破了$P这一招，手肘一送，摆脱了对方控制。\n"NOR;
	}
	message_combatd(msg, me, target);
	if( !target->is_fighting(me) ) target->fight_ob(me);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手三掌

	出手要求：
		金蛇游身掌100级
		内力300
HELP
	);
	return 1;
}

