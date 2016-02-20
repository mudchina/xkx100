
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「"HIG"幻化烟云"NOR "」"

int perform(object me,object target)
{
	string msg;
	object weapon, weapon2;
	int skill, ap,dp, damage;
	int flag;
	string fskill,sskill,bskill,pfname;

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

	//空手兵器均可

	fskill = "huiyan-xinfa";
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
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够, 使不出"+PNAME+"。\n");
	if(target->is_busy())
		return notify_fail(target->name() +"目前正自顾不暇，放胆攻击吧！\n");
	if( me->query("neili") < 100 )
		return notify_fail("你的内力不够，使不出"PNAME"！\n");
        msg = HIC "\n$N" HIC "双掌陡然连续反转，一招"PNAME+HIC"，双掌带风，已将$n" HIC "笼罩在掌风之中。\n" NOR;
 
   ap = me->query_skill(bskill,1);
   dp = target->query_skill("parry",1);
	if( dp < 1 )		dp = 1;
	if( random(ap) > dp/3 )
	{
		msg += HIR "结果$n" HIR "目不暇接，顿时被$N" HIR "掌"
                      "风所困，顿时阵脚大乱。\n" NOR;
		target->start_busy(ap/30+2);
		me->start_busy(1);
		me->add("neili",-200);
	}
	else
	{
     msg += HIY "$n" HIY "看清$N" HIY "这几招的来路，但"
                      "内劲所至，掌风犀利，也只得小心抵挡。\n" NOR;          
		me->start_busy(2);
		me->add("neili",-50);
	}
	message_combatd(msg, me, target);
	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		迟滞对方出手

	出手要求：
		回雁心法100级
		碧罗掌100级
		基本掌法100级
		内力100
HELP
	);
	return 1;
}

