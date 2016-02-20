// Last Modified by winder on Jul. 9 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME HIC"「风"HIW"雪"HIC"回剑」"NOR
int perform(object me, object target)
{
	object ob;
	object weapon;
	string msg;

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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n"); 

	fskill = "bingxue-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，还不能运用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if((int)me->query("max_neili") < 300)
		return notify_fail("你内力修为现在不够。 \n");

	if((int)me->query("neili") < 200)
		return notify_fail("你内力还现在不够。 \n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧。\n");

	msg = HIC"$N回剑旋舞，剑势不断加快，剑气呼啸四散，如片片雪花遇风，飘然而出。\n形成一个雪花形旋涡，将$n裹在内里。\n";
	if(random(me->query_skill("sword", 1) + me->query_skill("force", 1)) > (target->query_skill("dodge", 1) + (int)target->query_skill("parry", 1))/3)
	{
		msg +=HIG"$n"HIG"只觉得四周压力越来越大，道道暗流缠绕周身，几乎动弹不得。\n" NOR;
		target->start_busy( (int)me->query_skill(bskill,1) / 30);
		me->add("neili", -150);
		me->start_busy(1);
	} else
	{
		msg +=HIR"可是$n运足内力，雪花顿时全部溶解，一片不剩，脱出重围。\n" NOR;
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
		冰雪心法150级
		雪山剑法150级
		内力修为300
		内力200
HELP
        );
        return 1;
}


