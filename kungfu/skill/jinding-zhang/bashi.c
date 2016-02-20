// bashi.c 金顶绵掌 八式合一
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「八式合一」"
void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int count,d_count,qi, maxqi, skill;
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
		
	if( (int)target->query_temp("bashi") )
		return notify_fail("对方已经中了「八式合一」了。\n");

//	空手兵器均可

	fskill = "linji-zhuang";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 40 )
		return notify_fail("你的"+to_chinese(fskill)+"的修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"的八式修习不全，无法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("你的内力还不够高！\n");

	msg = HIY "$N"HIY"深深吸了一口气，提起全身的功力于双掌，只听的$N"HIY"骨骼一阵爆响！\n" NOR;
	me->add("neili",-100);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)
	{
		damage = (int)me->query_skill("force", 1)/2;
		damage = damage + (int)me->query_skill(bskill, 1);
		target->set_temp("bashi", 1);
		target->add_temp("apply/attack", -damage/3);
		target->add_temp("apply/dodge", -damage/3);
		msg += HIR "$N"HIR"腾空而起，使出了「八式合一」，漫天的掌影，飘忽不定的罩向$n"HIR"全身各个部位，\n" NOR;
    target->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/3, damage/3:), damage/30);
		target->start_busy(3);
	}
	else {
		msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
		me->start_busy(1);
	}
	message_combatd(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object target,int aamount, int damount)
{
	target->add_temp("apply/attack", aamount);
	target->add_temp("apply/dodge", damount);
	target->delete_temp("bashi");
	if (target->is_fighting())
	message_combatd(HIG"$N从猛烈的攻击中摆脱了出来，连退数步，稳住了脚步。\n"NOR, target);
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		降低对方的攻击力和防御力

	出手要求：
		临济十二庄40级
		金顶绵掌100级
		内力200
HELP
	);
	return 1;
}

