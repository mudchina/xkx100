// huayu.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "满天花雨"

int perform(object me, object target)
{
	int skill, i;
	string msg;
	object weapon, *ob;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");

	fskill = "huagong-dafa";
	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");
	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");
	skill = me->query_skill(bskill, 1);
	
	target->receive_damage("qi", (int)skill/ 3,me);

	msg= HIY"只听一股劲风从$N"HIY"的右侧发出，$N"HIY"手中的"+weapon->name()+"如烟雨般向$n"HIY"笼罩过去！\n"NOR;
	
	if(random(skill)>target->query_skill("parry")/2)
	{
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
		target->receive_wound("qi", skill+random(skill),me);
		target->start_busy(1+random(2));
		me->start_busy(1);
		me->add("neili", -200);
	} else {
		msg += "可是$p躲过了$P的最后一击。\n" NOR;
		me->start_busy(2);
		me->add("neili", -250);
	}
	message_combatd(msg, me, target);
	ob = all_inventory(me);	 //use out all throwing
	for(i=sizeof(ob)-1; i>=0; i--)
	{
		if( (string)ob[i]->query("equipped")!="wielded" ) continue;
		ob[i]->unequip();
		ob[i]->move(environment(me));
	}
	me->reset_action();
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
		化功大法100级
		飞星术100级
		内力300
HELP
	);
	return 1;
}

