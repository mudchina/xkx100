// Last Modified by Winder on Jul. 15 2001
// suiyuan.c

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「随缘三剑」"
mapping *msg = ({
([	"action":"$N使出随缘三剑中第一招「剑扫长虹」，$w幽灵般陡然刺向$n$l",
	"damage": 270,
	"force" : 200,
	"damage_type": "刺伤",
]),
([	"action": "$N使出随缘三剑中第二招「剑转乾坤」，$w幻出一道紫光刺向$n$l",
	"damage": 290,
	"force" : 260,
	"damage_type": "刺伤",
]),
([	"action":"$N使出随缘三剑中第三招「剑霸天下」，人影和着剑光风一般击向$n",
	"damage": 330,
	"force" : 300,
	"damage_type": "刺伤",
]),
});

int perform(object me, object target)
{
	object weapon;
	int i, damage, lvl;
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

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修为还不够高，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够高，无法使用"+PNAME+"。\n");

	if(me->query("max_neili") < 100)
		return notify_fail("你的内力修为不够，无法使「随缘三剑」。\n");

	if(me->query("neili") < 50)
		return notify_fail("你的内力不够，无法使「随缘三剑」。\n");

	if(target->is_busy())
		return notify_fail(target->name()+"目前正自顾不暇，放胆攻击吧！\n");


	lvl = me->query_skill(bskill, 1);
	me->start_busy(1);

	damage = lvl / 2;
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", damage);
	for(i=0;i<3;i++)
	{
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		me->set_temp("no_reset_action",1);
		me->set("actions", msg[i]);
		COMBAT_D->do_attack(me, target, weapon);
	}
	me->delete_temp("no_reset_action");
	me->reset_action();
	me->receive_damage("qi", damage / 2);
	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/damage", -damage);

	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		出手随缘三剑

	出手要求：
		寒冰真气60级
		嵩山剑法50级
		内力修为100
		内力50
HELP
	);
	return 1;
}

