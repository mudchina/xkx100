// xianglong 降龙大法
// Last Modified by Winder on Oct. 20, 2000

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me,int amount);
#define PNAME "降龙大法"
int perform(object me,object target)
{
	int skill, count;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");

*/
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手才能使用降龙大法。\n");
		
	if( (int)me->query_temp("xianglong") ) 
		return notify_fail("你已经在运降龙大法中了。\n");

	count = me->query_str();
	skill = me->query_skill("strike", 1);
	fskill = "huntian-qigong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修为还不够使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"修为还不够使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300  ) 
		return notify_fail("你的内力不够。\n");

	me->add("neili", -100);
	message_combatd( HIR "$N深吸一口气，运起降龙大法，结果越战越勇！\n" NOR, me);

	me->set_temp("xianglong", 1);
	me->add_temp("apply/strength", (int)count/5);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me , count/5 :), (int)(skill/6) );

	return 1;
}

void remove_effect(object me,int amount)
{
	int dmount;
	if ( (int)me->query_temp("xianglong") )
	{
	me->add_temp("apply/strength", - amount);
	me->delete_temp("xianglong");
	tell_object(me, CYN"你的降龙大法运行完毕，将内力收回丹田。\n"NOR);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增强自己的攻击力

	出手要求：
		混天气功100级
		降龙十八掌80级
		内力300
HELP
	);
	return 1;
}

