// kongming.c 空明拳 空明
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「空明」"
void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
  	string msg;
	int skill;
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

	//兵器空手均可
	
	if( (int)me->query_temp("kongming") ) 
		return notify_fail(HIG"你已经在运动「空明」了。\n"NOR);

	fskill = "xiantian-qigong";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能领悟"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"的修为不够，不能领悟"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("parry") != "kongming-quan") 
			return notify_fail("你未在招架中激发空明拳，无法使用空明！\n");
	}

	if( (int)me->query("neili") < 1200 )
		return notify_fail("你的内力还不够！\n");
	
	msg = HIY "$N使出空明拳的绝技进行招架，拳法虚虚实实，\n" NOR;

	skill = (int) (me->query_skill(bskill, 1) / 3);

	if((int)random(me->query("combat_exp")) >
		(int)target->query("combat_exp") / 2)
	{	
		me->set_temp("kongming", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 1, 0:), skill);
		msg += HIY "$n凶狠的招数毫无用武之地，招招象打在空气中！\n" NOR;
// 功效在combatd.c中体现
	}
	else{
		msg += HIR "但$n"HIR"不顾$N"HIR"拳法虚实，攻势潮涌如故！\n" NOR;
	}
	me->add("neili", -1000);
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me, int i, int j)
{
	if ( (int)me->query_temp("kongming") ) 
	{
		me->delete_temp("kongming");
		tell_object(me, HIY "你的空明运行完毕，将内力收回丹田。\n" NOR);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		以柔克刚，使对手出招大都落在空处

	出手要求：
		先天气功150级
		空明拳150级
		内力1200
HELP
	);
	return 1;
}

