// tougu.c 透骨针
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「透骨针」"
int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
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
		
	if (!objectp(weapon2 = target->query_temp("weapon")))
		return notify_fail("对方没有兵刃，你不用使透骨针。\n");

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

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使"+PNAME+"。\n");

	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够，无法使出"PNAME"！\n");
 
	skill = me->query_skill(bskill,1);
	msg = CYN"$N"CYN"使运出“透骨针”的内劲，$n"CYN"只觉得一股极阴寒的内力，贮于一点，从"+weapon->query("name")+CYN+"上传来，攻坚而入。\n"HIR;

	message_combatd(msg, me, target);
 
	ap = me->query("combat_exp") / 1000;
	dp = target->query("combat_exp") / 2000;
	if( dp < 1 ) dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me)) me->add("neili", -100);
		msg="$n胸口一痛，似乎被一枚极细的尖针刺了一下, 刺痛直钻入心肺，
手一松，"+weapon2->query("name")+"便被"+weapon->query("name")+"吸了过去。\n"NOR;
		target->start_busy(random(2));
		target->receive_damage("qi", skill+random(skill/2));
		weapon2->move(me);
		if (weapon2->query("ownmake")==1||weapon2->query("no_get"))
		{
			weapon2->move(environment(me));
			msg += "只听一声脆响！兵刃落地。\n" NOR;
		}
		me->start_busy(2);
	}
	else
	{
		msg = HIY"$n猝遇大变，心神不乱，飞起旋风腿，攻向$N, $N后跃避开。\n"NOR;
		me->start_busy(3);
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
		劫夺对方兵器

	出手要求：
		圣火令法100级
		九阳神功100级
		内力300
		使用圣火令
HELP
	);
	return 1;
}

