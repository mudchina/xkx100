// dian.c 凌虚点穴
// Last Modified by winder on Jun. 4 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "凌虚点穴"

int perform(object me, object target)
{
	string msg;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname;

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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("你要对谁使用"PNAME"！\n");
  if( environment(me)->query("no_fight") )
		return notify_fail("在这里不能攻击他人。\n");

  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//兵器空手均可
 
	if((int)me->query_str() < 25)
		return notify_fail("你臂力不够，不能使用"PNAME"！\n");
	fskill = "shenyuan-gong";
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
		return notify_fail("你的"+to_chinese(fskill)+"功力不够，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"修为不够，还不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你内力现在不够，不能使用"PNAME"！\n");
	if( target->is_busy() )
		return notify_fail(target->name() +"目前正自顾不暇，放胆攻击吧！\n");
	msg = HIY"$N"HIY"伸出食指，凌虚向$n"HIY"点了过去。指风尖锐如刀，带出细长的啸声。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P指风正中$p的胸口，$p微微一笑，行动竟丝毫不受阻碍，$P一惊之下，呆在当场。\n"NOR;
			me->start_busy(4);
			me->add("neili", -100);
		} else {
			msg +=  HIG "结果$p胸口一麻，便即摔倒在地下。\n" NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30)  + 2);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p双掌挡护胸前，恰恰封住$P的凌空指力。\n" NOR;
 		me->start_busy(4);
  }
  if ((int)me->query("str")>33 && 
    (int)me->query_skill("canhe-finger", 1) > 400 &&
    (int)me->query_skill("finger", 1) > 350 &&
     me->query("family/master_id") == "murong fu")
	{
		me->start_busy(2);
		target->start_busy(random(8));
		damage = (int)me->query_skill("canhe-finger", 1);
		damage = damage + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
	        me->add("neili", -200);
	        msg += HIC "一股阴寒的指风从$p"HIC"掌间渗入。\n" NOR; 
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
		后天膂力25
		神元功100级
		基本指法100级
		参合指100级
		内力300
HELP
	);
	return 1;
}

