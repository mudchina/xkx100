// tiaoyan.c 夺命三斧之「挑眼式」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "「挑眼式」"
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage;
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
		(string)weapon->query("skill_type") != "axe")
		return notify_fail("你使用的武器不对。\n");

	fskill = "kurong-changong";
	bskill = "axe";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"还使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"功力还使不出"+PNAME+"。\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("你的内力不够。\n");
	if( target->query_temp("block_msg/all") )
		return notify_fail(target->name()+ "正象只无头苍蝇，快放胆攻击吧。\n");
	msg = HIG "$N使出夺命三斧之「挑眼式」，斧尖疾挑$n双眼。\n";

	me->start_busy(1);
	me->add("neili", -200);

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		msg += "结果$p只觉得眼前一黑，双眼一阵剧痛，接着什么也看不见了。\n" NOR;
		damage = (int)me->query_skill(bskill, 1)/5;
		if (!target->is_busy())
		target->start_busy((int)me->query_skill(bskill, 1) / 30 + 3);
		target->receive_wound("qi", damage,me);
	  message_combatd(msg, me, target);
	  target->set_temp("block_msg/all",1);
	} else {
		msg += "可是$p看破了$P的企图，并急忙躲开了。\n" NOR;
	message_combatd(msg, me, target);
	}
//	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		使对方失去视觉直至下次登录

	出手要求：
		枯荣禅功150级
		断云斧150级
		内力600
HELP
	);
	return 1;
}

