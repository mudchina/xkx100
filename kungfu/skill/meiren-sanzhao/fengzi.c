// fengzi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "绝世风姿"
int perform(object me, object target)
{
	int level;
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
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

	if( (me->query("gender") != "女性" || me->query_per() < 20) &&	!wizardp(me) )
		return notify_fail("象你这副尊容，恐怕再怎么样，也没人多看你一眼的。\n");

	if( target->query("gender") != "男性" )
		return notify_fail("怎么了？卖弄风骚也要找个正确对象吧？\n");

	fskill = "dulong-dafa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不足，恐怕没法摆什么风姿了。\n");

	if( target->query_temp("shenlong/fengzi") )
		return notify_fail("他已经对你很倾倒了，你还浪费什么表情？\n");

	level = target->query_cps()/2;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cps() < random(me->query_per() * 2) )
	{
		message_combatd(HIC"激斗中，却见$N"HIC"忙中不乱，冲着$n"HIC"轻轻展颜露齿一笑，端的是艳若桃李、灿若明霞，容色柔媚无限，$n心中不觉一荡，油然升起一股亲近的感觉，眼神也渐渐迷茫起来。\n" NOR, me, target);
		target->set_temp("shenlong/fengzi", 1);
		target->add_temp("apply/composure", -level);
		target->start_busy(random(3)+1);
		target->start_call_out( (: call_other, __FILE__, "remove_effect", target, level:), 30);
	}
	else
	{
		message_combatd(HIY"只见$N"HIY"冲着$n"HIY"轻轻露齿一笑，露出了牙缝中一丝没咽下去的"HIG"菜叶"HIY"。\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object target, int level)
{
	target->delete_temp("shenlong/fengzi");
	target->add_temp("apply/composure", level);
	message_combatd(HIG"$N迷茫的眼神忽然一亮，心头猛地一震，忙收拢起心神来。\n" NOR, target);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗费自己的内力
		大幅降低对方的定力

	出手要求：
		毒龙大法50级
		美人三招60级
		自身为女性
		对手为男性
		内力300
HELP
	);
	return 1;
}

