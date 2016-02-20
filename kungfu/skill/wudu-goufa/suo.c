// suo.c 金钩锁魂
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "金钩锁魂"
int perform(object me, object target)
{
	object ob,weapon,myweapon;
	string msg, string1;
	int skill,myskill,attack_time,i;
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
		
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hook")
		return notify_fail(PNAME"开始时必须拿着一把钩！\n");

	if (!objectp(weapon = target->query_temp("weapon")))
		return notify_fail("对方手中并没有兵器！\n");

	fskill = "wudu-shengong";
	bskill = "hook";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"还不到家，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，使不出"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(bskill)+"还不到家，使不出"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	weapon=target->query_temp("weapon");
	myweapon=me->query_temp("weapon");
	message_combatd(HIR"\n$N虚晃一招，手中"+myweapon->query("name")+HIR"忽的一声，钩尖已搭在$n的"+weapon->query("name")+HIR"上！\n" NOR,me,target);
	skill = target->query_skill("parry", 1);
	myskill = me->query_skill(bskill, 1);
	if(random(myskill) < random(skill)||me->query("max_neili") <random(target->query("max_neili")))
	{
		msg = HIY "可是$n"HIY"早有准备，急忙收招跳开！\n" NOR;
		message_combatd(msg, me,target);
		me->start_busy(2);
		me->add("neili",-100);
		return 1;
	}

	msg = HIR"只见$N顺势一绞，低喝一声：“撒手！”$n只觉得虎口一阵巨痛，\n手中"+weapon->query("name")+HIR"当啷一声掉在地上！\n" NOR;
	msg += "$N哈哈一笑，得理不饶人，招招进逼！\n" NOR;
	message_combatd(msg, me,target);
	weapon->move(environment(me));

	attack_time = 3 + random(3);
	for(i = 0; i < attack_time; i++)
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
	target->start_busy(random(2));
	me->add("neili", -450);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手五钩
		击落对方兵刃

	出手要求：
		五毒神功50级
		基本钩法50级
		五毒钩法50级
		内力500
		使用五毒教的钩
HELP
	);
	return 1;
}

