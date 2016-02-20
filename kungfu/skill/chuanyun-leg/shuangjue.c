// shuangjue.c  拳腿双绝

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「拳腿双绝」"
int perform(object me, object target)
{
	int i, j, z, y;
	int flag;
	string fskill,sskill,bskill,pfname,pskill,cskill,cskill1;

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

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「拳腿双绝」！\n");
		
	fskill = "xuantian-wuji";
	bskill = "leg";
	cskill = "cuff";
	cskill1= "zhentian-cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
		cskill = "force";
		cskill1= "shenyuan-gong";
	}
	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("cuff") != "zhentian-cuff" ||
			me->query_skill_prepared("leg") != "chuanyun-leg" ||
			me->query_skill_mapped("cuff") != "zhentian-cuff" ||
			me->query_skill_mapped("leg") != "chuanyun-leg")
			return notify_fail("你现在无法使用"PNAME"进行攻击！\n");
	}
	if( (int)me->query_skill(cskill1, 1) < 100 )
		return notify_fail("你的"+to_chinese(cskill1)+"不够娴熟，无法施展"PNAME"。\n");
	if( (int)me->query_skill(cskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(cskill)+"不够娴熟，无法施展出"PNAME"。\n");
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，无法施展出"PNAME"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，无法施展"PNAME"。\n");
	if ((int)me->query_skill(fskill, 1) < 100)
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，无法施展出"PNAME"。\n");
	if( (int)me->query_dex() < 30 )
		return notify_fail("你的身法欠佳，无法施展出"PNAME"。\n");
	if ( (int)me->query("max_neili") < 500)
		return notify_fail("你的内力不够，无法施展出"PNAME"。\n");
	if ( (int)me->query("neili") < 400)
		return notify_fail("你的真气不够，无法施展出"PNAME"。\n");
	i = me->query_skill(cskill,1);
	j = me->query_skill(bskill,1);
	z = me->query_skill("force",1);
	y = (i+j+z)/20;
	message_combatd(RED"$N"RED"一声清啸，拳脚齐施，使出昆仑绝学「拳腿双绝」迅捷无伦地攻向$n"RED"！\n"NOR,me, target);
	me->add("neili", -400);
	me->add_temp("apply/strength", y);
	me->add_temp("apply/attack", y);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
	me->add_temp("apply/strength", -y);
	me->add_temp("apply/attack", -y);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		加力连续出手五招

	出手要求：
		玄天无极功100级
		基本腿法100级
		基本拳法100级
		震天拳法100级
		穿云腿100级
		后天身法30
		内力修为500
		内力400
HELP
	);
	return 1;
}

