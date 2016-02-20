// banruo-zhang's perform yipai(一拍两散)
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#define PNAME "一拍两散"
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage, p,t_neili,m_neili,t_force,m_force,m_exp,t_exp,
	m_skill,t_skill,m_max_neili,t_max_neili;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用"PNAME"！\n");

	fskill = "yijinjing";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，使不出"PNAME"！\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够熟练，不能使用"PNAME"绝招对敌！\n");
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"还不够熟练，不能使用"PNAME"绝招对敌！\n");
	if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你内力修为不足，使不出"+to_chinese(sskill)+"的绝招！\n");
	if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("你现在内力不足，使不出"+to_chinese(sskill)+"的绝招！\n");

	t_neili=target->query("neili");
	m_neili=me->query("neili");
	t_max_neili=target->query("max_neili");
	m_max_neili=me->query("max_neili");
	t_force=target->query_skill("force",1);
	m_force=2*me->query_skill("force",1);
	m_exp=me->query("combat_exp");
	t_exp=target->query("combat_exp");
	m_skill=2*me->query("strike",1);
	t_skill=target->query_skill("parry",1);
	msg = WHT"\n$N"WHT"大声喝道："HIY"“吃我一掌！”"WHT"双掌自外向里转了个圆圈，缓缓向$n"WHT"推了过来。\n掌力未到，$n"WHT"已感胸囗呼吸不畅，顷刻之间，$N"WHT"的掌力如怒潮般汹涌而至！！\n\n"NOR;	
	if ((random(m_force) > t_force/2) && (random(m_exp)>t_exp/3))
	{
		me->start_busy(1);
		target->start_busy(1); 
		damage=(m_force+me->query("jiali")+m_skill+(m_max_neili-t_max_neili)/10); 
		damage = damage*3/2 + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage/3,me);
		me->add("neili", -1000);
		p =(int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 0, me, target, p);    
	} else 
	{
	msg += BLU "$p"BLU"撤招换掌，右掌迎了过去。两股掌力相交，嗤嗤有声，只听见“砰”的一声，\n双方均退了三步。\n" NOR;
		if (t_neili>m_neili )
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -500);
			target->add("neili",-500);
		}
		else
		{
			me->start_busy(2);
			target->start_busy(1);
			me->add("neili", -t_neili/2);
			target->add("neili",-t_neili);
		}
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
		重创对手精气和气血

	出手要求：
		易筋经120级
		般若掌120级
		基本掌法120级
		内力1000
		内力修为1500
HELP
	);
	return 1;
}

