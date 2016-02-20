// lingshe.c 灵蛇飞舞
// Last Modified by sir on 4/26/2001

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "灵蛇飞舞"
int perform(object me, object target)
{
	string msg;
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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
        return notify_fail("你要对谁使用灵蛇飞舞！\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");
		
  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//兵器空手均可

	if((int)me->query_str() < 25)
		return notify_fail("你膂力不够，不能使用这一绝技！\n");
		
	fskill = "hamagong";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，目前还不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"的功力不够不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够, 不能使用灵蛇飞舞! \n");

	if( target->is_busy() )
		return notify_fail(target->name() +"目前正自顾不暇，放胆攻击吧！\n");

	msg = HIY"$N使出蛇形刁手绝技「灵蛇飞舞」，十指伸缩，如千万只吐信灵蛇，虚虚实实地袭向$n的全身要穴。$n不及攻敌，拼力躲避$N手法顿时动作大乱。\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg +=HIY"$P一下点中$p的大穴，$p只觉微微一麻，迅即行动如常。\n"NOR;
			me->start_busy(random(4) + 1);
			me->add("neili", -100);
		} else {
			msg +=  HIG "结果$p被$P点中几处穴道! \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill,1) / 30) + 2);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p情急智生，狠力一跃，退出老远。\n" NOR;
		me->start_busy(3);
	        if(!target->is_fighting(me) && target->query("owner") && 
		        me->query("id") == target->query("owner"))
	        target->fight_ob(me);
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
		迟滞对方出手

	出手要求：
		蛤蟆功100级
		蛇形刁手100级
		后天膂力25
		内力300
HELP
	);
	return 1;
}

