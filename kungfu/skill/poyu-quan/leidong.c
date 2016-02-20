// leidong 雷动九天
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_SSERVER;
#define PNAME "雷动九天"
int perform(object me,object target)
{
	int skill, count, count1;
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

/*	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
*/		
	// 兵器空手均可
	fskill = "zixia-shengong";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
        if( (int)me->query_temp("leidong") ) 
                return notify_fail("你已经在运功中了。\n");

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"功力不够使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"功力不够使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(bskill)+"功力不够使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500  ) 
		return notify_fail("你的内力不够。\n");

	count = me->query_str();
	skill = me->query_skill(bskill, 1);

	me->add("neili", -400);
	message_combatd( HIM "$N深深吸了一口气，脸上顿时紫气大盛，出手越来越重！\n" NOR, me);

	count = me->query("str") + (int)(skill/30);
	count1 = (int)(me->query("dex")/2);

	me->add_temp("apply/strength", count);
	me->add_temp("apply/dexerity", -count1);
	me->set_temp("leidong", 1);
	me->start_call_out( (: call_other,  __FILE__, "remove_effect", me, count, count1 :), skill/3 );

	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ( (int)me->query_temp("leidong") ) 
	{
		me->add_temp("apply/strength",-amount);
		me->add_temp("apply/dexerity", amount1);
		me->delete_temp("leidong");
		tell_object(me,CYN"你的雷动九天运行完毕，将内力收回丹田。\n"NOR);
		me->start_busy(4);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		临时提升自己的攻击力，降低防御力

	出手要求：
		紫霞神功100级
		基本拳法135级
		破玉拳100级
		内力500
		后天膂力25
HELP
	);
	return 1;
}

