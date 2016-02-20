// ningxue.c 凝血神爪
// Last Modified by sir on 5/5/2001

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "凝血神爪"
int perform(object me, object target)
{
	string msg;
	int damage,skill;
	object weapon;
	string limb;
	mapping limbs;
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

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手运功。\n");

	if((int)me->query_str() < 30)
		return notify_fail("你膂力不够，不能使用凝血神爪！\n");

	fskill = "yunlong-shengong";
	bskill = "claw";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，目前还不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，目前还不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 800)
		return notify_fail("你内力现在不够，不能使用凝血神爪！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");

	msg = HIR "$N使出云龙爪绝技「凝血神爪」，真气灌注双爪抓向$n。\n"NOR;

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
    if (arrayp(limbs = target->query("limbs")))
         limb = limbs[random(sizeof(limbs))];
    else
         limb = "要害";
		msg+=HIR "$n连忙腾挪躲闪，然而“扑哧”一声，$N"
         HIR "五指正抓在$n" HIR "的" + limb + "，只听得$n"
         HIR "一声惨叫，鲜血横飞。\n" NOR;
 		skill = me->query_skill(bskill, 1) * 2;
		damage = skill + (int)me->query_skill("force", 1)/2;
		me->add("neili", -300);
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", damage,me);		
		target->receive_wound("qi", damage/4,me);
		target->receive_damage("jing", damage*7/10,me);
		target->receive_wound("jing", damage/3,me);
		target->add("neili", -600);
	}
	else {
		msg += HIG "可是$p看破了$P的企图，腾身避开,并没有中招。\n" NOR;
		me->start_busy(4);
		me->add("neili", -100);
	}
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
                伤敌气血和精气

        出手要求：
                云龙神功120级
                云龙爪150级
                后天膂力30
                内力800
HELP
        );
        return 1;
}

