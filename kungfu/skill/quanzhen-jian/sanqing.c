// sanqing.c  一剑化三清
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「一剑化三清」"
int perform(object me, object target)
{
  object weapon, ob;
        string msg, string1;
        int count,sword_lvl;
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
    return notify_fail(PNAME"开始时必须拿着一把剑！\n");

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

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"不够使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");

  if( (int)me->query("neili") < 100 )
    return notify_fail("你的真气不够！\n");

  msg =  HIY "$N"HIY"大喝一声，剑招突变，长剑逼出雪亮光芒，一剑化为三剑，剑剑快似闪电！\n" NOR;
// 全心一片空明，剑在意先，使出「一剑化三清」，剑尖连闪，化为三剑，沛然而至！

//  me->clean_up_enemy();
 // ob = me->select_opponent();
  message_combatd(msg, me);
  sword_lvl =(int)me->query_skill("sword", 1)/15;
  for(count=1;count<=3;count++)
  {
  	if (flag == 1) target = offensive_target(me);
  	if (!objectp(target)) break;
     me->add_temp("apply/dodge",sword_lvl);
     me->add_temp("apply/attack",sword_lvl);
     me->add_temp("apply/sword",sword_lvl);
    msg =  HIR "第"+chinese_number(count)+"剑！" NOR;
    message_combatd(msg, me);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
  }
  me->add_temp("apply/dodge",-count*sword_lvl);
  me->add_temp("apply/attack",-count*sword_lvl);
  me->add_temp("apply/sword",-count*sword_lvl);
  
  me->add("neili", -100);
  me->start_busy(random(3));

  if(!target->is_fighting(me)) target->fight_ob(me);
  return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
  write(@HELP

  使用功效：
    连续出手三剑

  出手要求：
    先天气功60级
    全真剑法135级
    内力100
HELP
  );
  return 1;
}

