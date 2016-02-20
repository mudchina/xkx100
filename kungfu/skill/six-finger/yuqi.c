// yuqi.c 驭剑气
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「驭剑气」"
int perform(object me,object target)
{
	string msg;
	object weapon, target_w,piece;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
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
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手运功。\n");

	fskill = "kurong-changong";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使"+PNAME+"。\n");

	if( me->query_str() < 30)
		return notify_fail("你的臂力不够，无法运功！\n");
 
	if( me->query("neili") < 1500 )
		return notify_fail("你的内力不够，无法运功！\n");
 
	skill = me->query_skill(bskill,1);
	msg = HIY "$N忽然心头大乱，十指乱伸，内息滚动，直是连绵无尽。霎时
间剑气纵横，尘烟四起，\n"NOR;


	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 ) dp = 1;
//	if(userp(me)) me->add("neili", -800);
	if( random(ap) > dp )
	{
		qi_wound = (int)me->query_skill(bskill,1) * 2;
		qi_wound = qi_wound/2 + random(qi_wound);
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
		target->receive_damage("qi", qi_wound,me);
		target->receive_wound("qi", qi_wound,me);
		target->start_busy(2);
		me->start_busy(random(3));
		me->add("neili", -1000);

		msg += HIR"$n顿时手足无错，全身刺痛锥心，鲜血标出丈多远！\n"NOR;
		if (objectp(target_w = target->query_temp("weapon")))
		{
			target_w->unequip();
			target->reset_action();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆破碎物事，很象兵器碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
			msg += HIY "同时只听到「叮当」一声兵刃破碎的声音，$n顿觉手中一震，兵器竟被剑气误打误撞，脱手而出！\n" NOR;
		}
	}
	else
	{
		msg += HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的气剑！\n"NOR;
		me->start_busy(4);
		me->add("neili", -500);
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
		损毁对方兵刃

	出手要求：
		枯荣禅功150级
		六脉神剑120级
		内力1500
		后天膂力30
HELP
	);
	return 1;
}

