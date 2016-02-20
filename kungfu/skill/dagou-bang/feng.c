// feng.c 打狗棒法「封」字诀
// Last Modified by winder on Nov. 16 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「封字诀」"
int perform(object me, object target)
{
	string msg;
	object weapon;
	int skill;
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

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "stick")
		return notify_fail(HIY "你需要合适的兵器才封得住。\n" NOR);
	if (target->query_temp("dagou/feng"))
		return notify_fail(HIR"你已经使出“封”字诀了！\n"NOR);
	fskill = "huntian-qigong";
	bskill = "stick";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");

	if((int)me->query("max_neili") < 500)
		return notify_fail(HIY "你的内力修为还不够火候。\n" NOR);
	if((int)me->query("neili") < 500)
		return notify_fail(HIY "你现在真气不足。\n" NOR);
	skill = me->query_skill(bskill,1);
	skill = (int)(skill/4)+ random((int)(skill/4));

	msg = HIC "$N"HIC"心神稍定，一咬牙，提起手中"+weapon->name()+HIC"，紧紧守住门户，\n"NOR;

	if (random(me->query_dex()) > target->query_dex()/2)
	{
		msg += HIC"使个“封”字诀，棒影飘飘，登时将$n"HIC"身前数尺之地尽数封住了。\n"NOR;
		message_combatd(msg, me, target);
		me->add("neili", -400);
		me->add_temp("apply/defense", skill);
		target->set_temp("dagou/feng", 1);
		call_out("feng_end", (int) 6+random(6), me, target, skill);
	} else
	{
		me->start_busy(2);
		me->add("neili", -300);
		msg += HIY"$n猛然一出手，恰恰堵住了$N"HIY"的封字诀。\n"NOR;
		message_combatd(msg, me, target);
	}
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

void feng_end(object me, object target, int skill)
{
	if (objectp(me) && objectp(target))
	message_combatd(HIR"$n乘$N稍一松懈，从$N的封字诀中突围而出。\n"NOR, me, target);
	if (objectp(me))
	me->add_temp("apply/defense", -skill);
	if (objectp(target))
	target->delete_temp("dagou/feng");
	return;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		暂时性使提升自己招架能力
		暂时性使对手不能运用外功

	出手要求：
		混天气功180级
		打狗棒法180级
		内力修为500
		内力500
HELP
	);
	return 1;
}

