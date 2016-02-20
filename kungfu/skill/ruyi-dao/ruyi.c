// ruyi.c 如意连环刀
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>
#define PNAME "「如意连环刀」"
#include <combat.h>
#include <xiaoyao.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	object weapon;
	int flag;
	string fskill,sskill,bskill,pfname;
	int extra;

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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail(HIY "你必须用刀才能施展。\n" NOR);

	fskill = "beiming-shengong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不会使用"+PNAME+"。\n");
	if((int)me->query("neili") < 400)
		return notify_fail(HIY "你现在真气不足。\n" HIY);

	extra = me->query_skill("ruyi-dao",1)/6;
	if (fam_type(me)=="xiaoyao")	extra *= 2;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        me->add("neili", -200);
        
        msg = HIY "$N一声长笑，只觉世事如意，豪气满胸，哪管什么是非荣辱，反手一刀砍出！"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg = HIB"$N刀风过处，意犹未尽，反手又是一刀！"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR"$N身随刀转，顺手又是一刀！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIW"$N身形再转，如意一刀又回转回来！"NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(1);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出招

	出手要求：
		如意刀60级
		北冥神功60级
		内力400
HELP
	);
	return 1;
}

