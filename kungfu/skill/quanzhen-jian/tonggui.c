// tonggui.c 全真剑法 同归剑法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「同归剑法」"
int perform(object me, object target)
{
	object weapon;	
	string msg;
	int d_count, count, qi, maxqi, skill,damage;
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

	if( !objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("没有剑在手怎么能用同归剑法？\n");
		
	fskill = "xiantian-qigong";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 10 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"修为太浅，未领会"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够！\n");

	qi = me->query("qi");
	maxqi = me->query("max_qi");
	if(qi > (maxqi * 0.4))
		return notify_fail("你现在的身体状况无法激发同归剑法！\n");

	skill = (int) (me->query_skill(bskill, 1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	msg = HIY"$N使出「同归剑法」，剑气纵横，只攻不守，招招拼命，凶狠危险之至！\n" NOR;
	if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		damage = target->query("qi");
		target->receive_damage("qi", damage-10,me);
		target->receive_wound("qi", damage-10,me);
		msg += HIC "$n疾忙斜跃，但剑急如电，只觉一阵钻心剧痛，剑尖扎入胸前，鲜血飞溅！\n"NOR;
		me->set("neili",0);
	}
	else
	{
		me->start_busy(2);
		me->set("neili",100);
		msg += HIY"可是$n微微一笑，气定神闲，身形轻变，闪过剑招。\n"NOR;
	}

	message_combatd(msg, me, target);
	if(userp(target)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗尽全部内力，出手一剑

	出手要求：
		先天气功100级
		全真剑法150级
		内力500
HELP
	);
	return 1;
}

