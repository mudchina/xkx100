// zuida.c 少林醉棍 [八仙醉打]
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「八仙醉打」"
void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int count, count1, cnt, skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
*/
	if (!objectp(weapon = me->query_temp("weapon")) || 
	(string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_temp("jingang") ) 
		return notify_fail("你已经在运大金刚神通了。\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail("你已经在运功中了。\n");

	if( (int)me->query_temp("powerup"))
		return notify_fail(HIG "你已经运起内功加力了，没有更多的内力使用八仙醉打。\n"NOR);

	if( (int)me->query_str() < 25 )
		return notify_fail("你的臂力不够，目前不能使用此绝技！\n");
		
	fskill = "hunyuan-yiqi";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不足！\n");

	cnt =(int)( (int)me->query_condition("drunk") / 3 );
	if( cnt < 2 )
		return notify_fail("你的醉意不足激发醉打！\n");

	msg = HIY"$N使出少林醉棍的绝技「八仙醉打」，臂力陡然增加, 身法陡然加快！\n" NOR;
	
   	message_combatd(msg, me, target);
	skill = me->query_skill("club", 1);
	count = me->query("str") * random(cnt + 1);
	count1 = me->query("dex") * random(cnt + 1);
	if (count > 100);
	   else (count = 100);
	if (count < 50);
	   else (count =50);
	if (count1 > 60);
	   else (count1 = 60);
	if (count1 < 50);
	    else (count1 =50);
	me->add_temp("apply/strength", count);
	me->add_temp("apply/dexerity", count1);
	me->set_temp("zuida", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count, count1 :), skill /3 );

	me->add("neili", -150);
   	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ( (int)me->query_temp("zuida") ) 
	{
		me->add_temp("apply/strength",-amount);
		me->add_temp("apply/dexerity",-amount1);
		me->delete_temp("zuida");
		tell_object(me, HIY "你的八仙醉打运功完毕，将内力收回丹田。\n" NOR);
		me->start_busy(4);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增强自己的攻击力和防护力

	出手要求：
		混元一气功60级
		少林醉棍90级
		基本棍法90级
		内力500
		后天膂力25
		喝醉
HELP
	);
	return 1;
}

