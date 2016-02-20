// Last Modified by Winder on May. 21 2001
// jianqi.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「剑气」"
int perform(object me, object target)
{
	object weapon;
	int damage, sword;
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
		weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能运用「剑气」？！\n");
		
	if (weapon->query("unique") )
		return notify_fail("你手中之剑已是锋利之极，使用「剑气」没有什么作用！\n");

	if( me->query_temp("ss_jianqi") )
		return notify_fail("你刚使完「剑气」，目前气血翻涌，无法再次运用！\n");

	fskill = "hanbing-zhenqi";
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
		return notify_fail("你的"+to_chinese(fskill)+"修为火候未到，施展只会伤及自身！\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修为还不够，还未能领悟"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"修为还不够，还未能领悟"+PNAME+"。\n");

	if( (int)me->query_str() < 30 )
		return notify_fail("你的臂力不够高，无法使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill_mapped("force") != fskill )
			return notify_fail("你所用的内功与「剑气」心法相悖！\n");
	}

	if( me->query("max_neili") <= 2000 )
		return notify_fail("你的内力修为不足，劲力不足以施展「剑气」！\n");

	if( me->query("neili") <= 600 )
		return notify_fail("你的内力不够，劲力不足以施展「剑气」！\n");

	message_combatd(GRN "\n刷的一声响，$N潜运内力将"+weapon->name()+GRN"一抖。这一下使得剑气纵横，竟然声震山谷。不明其理之人，无不骇异！\n\n" NOR, me);

	damage = me->query_skill(bskill, 1);
	damage = damage/6;
	sword = me->query_skill(bskill, 1)/3;
	if ( userp(me) )
	{
		me->add("neili", -300);
		if ( damage > weapon->query("weapon_prop/damage") * 2)
			damage = weapon->query("weapon_prop/damage") * 2;
		else weapon->add("rigidity", 1);
	}

	me->set_temp("ss_jianqi", 1); 
	me->add_temp("apply/damage", damage);
	me->add_temp("apply/attack", damage);
	
	call_out("remove_effect1", sword/2, me, weapon, damage);
	call_out("remove_effect2", sword*2/3, me);

	return 1;
}

void remove_effect1(object me, object weapon, int damage) 
{
	object piece;
	if (!me) return;
	me->add_temp("apply/attack", -damage);

	if (!objectp(weapon))
	{
		me->set_temp("apply/damage", 0);
		return;
	}
	me->add_temp("apply/damage", -damage);
	message_combatd("\n$N一套「嵩山剑法」使完，手中"+weapon->name()+"上的光芒渐渐也消失了。\n", me);		
	weapon->add("jianqi", 1);
	if (weapon && weapon->query("jianqi") >= (3+weapon->query("rigidity")))
	{
		message_combatd(HIW"\n只听“嚓”的一声，$N手中的$n"HIW"被内力冲击，裂成了碎片！\n"NOR,me,weapon);
		weapon->unequip();
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆兵器的碎片。\n");
      	piece->set_name( "碎裂的" + weapon->query("name"), ({weapon->query("id"),"piece"}) );
      	piece->move(environment(me));
     		destruct(weapon);
		me->reset_action();
	}
}

void remove_effect2(object me)
{
	if (!me) return;
	me->delete_temp("ss_jianqi");
	tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「剑气」了。\n"NOR); 
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		内力灌注兵器增加杀伤力

	出手要求：
		寒冰真气150级
		嵩山剑法150级
		基本剑法150级
		后天膂力30
		内力修为2000
		内力600
HELP
	);
	return 1;
}

