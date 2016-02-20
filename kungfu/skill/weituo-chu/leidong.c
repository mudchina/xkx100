// Last Modified by winder on May. 29 2001
#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「雷动九天」"
int perform(object me, object target)
{
	object weapon;
	int damage, club;
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
	if( !objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("skill_type") != "club" )
		return notify_fail("你手中无棍，怎能运用「雷动九天」？！\n");

	if( me->query_temp("sl_leidong") )
		return notify_fail("你刚使完「雷动九天」，目前气血翻涌，无法再次运用！\n");

	fskill = "yijinjing";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"修为火候未到，施展只会伤及自身！\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修为还不够，还未能领悟"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill)
		return notify_fail("你所用的内功与"PNAME"心法相悖！\n");

	if( (int)me->query_str() <=30 )
		return notify_fail("你的膂力现在无法使用"PNAME"。\n");

	if( me->query("max_neili") <= 2000 )
		return notify_fail("你的内力修为不足，劲力不足以施展"PNAME"！\n");

	if( me->query("neili") <= 600 )
		return notify_fail("你的内力不够，劲力不足以施展"PNAME"！\n");

	message_combatd(BLU"\n突然$N"BLU"大喝一声：「雷动九天」，面色唰的变得通红，须发皆飞，真气溶入"+weapon->name()+BLU"当中，“嗡”的一声，发出"HIW "闪闪光亮"BLU"！\n" NOR, me);
	damage = me->query_skill(bskill, 1)+me->query_skill("force", 1);
	damage /= 6;
	club = me->query_skill(bskill)/3;
	if ( userp(me) )
	{
		me->add("neili", -300);
		if ( damage > weapon->query("weapon_prop/damage") * 2)
			damage = weapon->query("weapon_prop/damage") * 2;
		else weapon->add("rigidity", 1);
	}
	me->set_temp("sl_leidong", 1); 
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	call_out("remove_effect1", club/2, me, weapon, damage);
	call_out("remove_effect2", club*2/3, me);
	return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
	if (!me) return;
	me->add_temp("apply/attack", -damage);  
	if (!weapon)
	{
		me->set_temp("apply/damage", 0);
		return;
	}
	me->add_temp("apply/damage", -damage);
	message_combatd(HIY"\n$N一套「雷动九天」使完，手中"NOR+weapon->name()+HIY"上的光芒渐渐也消失了。\n"NOR, me);		
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("sl_leidong");
	tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「雷动九天」了。\n"NOR); 
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增大兵器伤害力

	出手要求：
		易筋经150级
		韦陀杵150级
		后天膂力30
		内力修为2000
		内力600
HELP
	);
	return 1;
}

