// fumo.c 大金刚拳 perform 金刚伏魔

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「金刚伏魔」"
int perform(object me, string arg)
{
	object target;
	string msg;				   
	int i,z;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用"PNAME"！\n");

	fskill = "yijinjing";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if(me->query_skill_mapped("force") != fskill)
			return notify_fail("你没有运用"+to_chinese(fskill)+"内功，无法使用"PNAME"进行攻击。\n"); 

	if(me->query_temp("fenxin"))
		return notify_fail("你现在正在使用焚心绝技，不能用"PNAME"。\n"); 
	if( (int)me->query_str() < 28 )
		return notify_fail("你的臂力不够强，不能使用"PNAME"！\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力太弱，不能使用"PNAME"！\n");
	if( (int)me->query("neili") < 700 )
		return notify_fail("你的内力太少，无法使用出"PNAME"！\n");
	if( me->query_temp("fumo")   )
		return notify_fail("你正在使用大金刚拳的"PNAME"！\n");

	i = (int)me->query_str() * 2;
	z = (int)me->query_skill("force", 1)/5+(int)me->query_skill(bskill,1)/4;
	msg = HIR"$N突然全身骨骼作响，口中默念「金刚伏魔」，运起易筋经神功，脸上一阵红色，全身好象有使不完的力量一样！\n" NOR;
	message_combatd(msg, me, target); 
	me->add_temp("apply/strength", i);
	me->set_temp("fumo", 1);
	me->add("neili", - 600);

	call_out("check_fight", 1, me, i, z);
	me->start_busy(1);
	return 1;
}
void remove_effect(object me, int i)
{
	if(me->query_temp("fumo"))
	{
//		me->delete_temp("apply/strength");
		me->add_temp("apply/strength",-i);
		me->delete_temp("fumo");
		tell_object(me,HIR"你的「金刚伏魔」运功完毕，脸色也好看多了。\n"NOR);
	}
}
void check_fight(object me, int i, int z)
{
	if (!me) return;
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon") )
	{
		remove_effect(me, i);
		return;
	}
	if (z < 1 || !me->is_fighting())
	{
		remove_effect(me, i);
		return;
	}
	call_out("check_fight", 1, me, i, z-1);
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		可使臂力增强六倍，一招毙敌于掌下

	出手要求：
		后天臂力28
		易筋经100
		大金刚拳120
		内力1000
HELP
	);
	return 1;
}

