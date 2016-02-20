// tianlei.c 铁掌掌法 「天雷气」
// Last Modified by winder on Aug. 28 2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「天雷气」"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用天雷气！\n");

	fskill = "guiyuan-tunafa";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"还未练成，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用天雷气！\n");	
	msg = HIY"\n$N忽然仰天大喝一声“天 雷 气”，双掌如风车般连环击出，一阵热浪随掌势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") )
	{
		if( random(me->query_str()) > (int)target->query_str()/2 )
		{
			msg +=HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中" + weapon->query("name") + HIM+"脱手而出。\n" NOR;
			message_combatd(msg, me, target);
			(target->query_temp("weapon"))->move(environment(target));
		}
		else
		{
			msg +=HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
			message_combatd(msg, me, target);
		}
		me->start_busy(1);
	}
	else
	{
		if (random(me->query_skill("force")) > target->query_skill("force")/2 )
		{
			me->start_busy(3);
			target->start_busy(random(3));
			damage = (int)me->query_skill("force", 1);
			damage += (int)me->query_skill("strike", 1);
			damage = damage * 2 + random(damage);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage / 2,me);
			if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
			else if(damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
				else if(damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
					else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		}
		else 
		{
			me->start_busy(1);
			msg +=HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		}
		message_combatd(msg, me, target);
	}
	me->add("neili", -600);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		劫夺对方兵刃或伤害对方气血

	出手要求：
		归元吐纳法120级
		铁掌掌法120级
		上官剑南亲传弟子
		内力600
HELP
	);
	return 1;
}

