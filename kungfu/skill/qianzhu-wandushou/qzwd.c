// qianzhu-wandushou.c 千蛛万毒
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "千蛛万毒"
int perform(object me, object target)
{
	string msg;
	int damage, skill;
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
		
		//空手兵器均可
		
	fskill = "wudu-shengong";
	bskill = "hand";
	pskill = "five-poison";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		pskill = "shenyuan-gong";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"的功力不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，还不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(pskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(pskill)+"太低，不能使用"+PNAME+"。\n");
//	if( !userp(me))
//		return notify_fail("只有玩家才能玩命。\n");
	if((int)me->query("max_neili") < 700)
		return notify_fail("你内力修为不够，不能使用"PNAME"！\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你内力不够，不能使用"PNAME"！\n");

	if(me->query_temp("qzwd_used"))
		return notify_fail("你刚使用过千蛛万毒，无法在短时间里积聚毒力！\n");

	skill = me->query_skill(bskill,1);
	msg = HIR "$N"HIR"一声狞笑飞身纵起，凌空一指向$n"HIR"的眉心点去。\n";
	message_combatd(msg, me, target);

	if( random(skill) > random((int)target->query_skill("dodge",1)*2/3))
	{
		msg=HIR"只见一缕黑气从$N"HIR"的指尖透出，只一闪就没入$n"HIR"的眉心！\n"NOR;
		message_combatd(msg, me, target);
		if(target->query_skill("force", 1) > skill * 12 /10 &&
			random(2)==0)
		{
			msg = RED"$N忽然觉得指力被一团无形的劲力包裹着，紧接着只听\n$n一声大喝，$N顿时如一根稻草般被抛向远处。\n" NOR;
			message_combatd(msg, me, target);
			msg = RED"$P只觉得一股如山的劲力顺指尖猛攻过来，只觉得全身毒气狂窜。\n忽然胸口一痛，不由“哇”的一声吐出一口黑血！\n" NOR;
			message_combatd(msg, me);
			damage = skill +(int)me->query_skill("force",1);
			if(damage < 50 ) damage = 50;
			me->receive_wound("qi", damage,target);
			me->add("neili", -100);
			me->start_busy(2);
		}
		else{
			msg = HIR"$n"HIR"不由一声惨嚎摔倒在地，身体已痛苦得蜷缩成一团！\n" NOR;
			message_combatd(msg, me, target);
			damage= skill + (int)me->query_skill("force", 1)/2;
			if(damage > 900 ) damage = 900;
			target->receive_wound( "qi",damage,me);
			if( me->query_skill(pskill, 1) > 100)
			{
				target->apply_condition("snake_poison", (int)target->query_condition("snake_poison") + 50 );
				target->apply_condition("wugong_poison", (int)target->query_condition("wugong_poison") + 50 );
				target->apply_condition("zhizhu_poison", (int)target->query_condition("zhizhu_poison") + 50 );
				target->apply_condition("xiezi_poison", (int)target->query_condition("xiezi_poison") + 50 );
				target->apply_condition("chanchu_poison", (int)target->query_condition("chanchu_poison") + 50 );
			}
			me->add("neili", -300);
			target->start_busy(4);
		}
	}
	else {
		msg = HIG "可是$n早有准备，一个懒驴打滚，堪堪躲过了这一招。\n" NOR;
		me->start_busy(4);
		message_combatd(msg, me, target);
		me->add("neili", -100);
	}
	if( !target->is_killing(me) ) target->kill_ob(me);
	me->set_temp("qzwd_used",1);
	call_out ("qzwd_used", 6,me);
	return 1;
}
void qzwd_used(object me)
{
	me->delete_temp("qzwd_used");
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		使对手身中五毒（蛇、蝎子、蜈蚣、蟾蜍、蜘蛛）

	出手要求：
		五毒神功80级
		五毒毒技100级
		千蛛万毒手100级
		内力修为700
		内力500
HELP
	);
	return 1;
}

