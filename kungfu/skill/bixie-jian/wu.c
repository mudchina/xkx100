// sanqing.c  一剑化三清
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

#define PNAME "「群魔乱舞」"
inherit F_SSERVER;
 
int perform(object me, object target)
{
  object weapon, ob;
	string msg, string1;
	int count,sword_lvl;
	int  i , j;
	int flag;
	string fskill,sskill,bskill,pfname;

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
    (string)weapon->query("skill_type") != "sword")
    return notify_fail(PNAME"必须拿着剑才能出！\n");
  if (!userp(me)) return notify_fail("npc不在这里使用这招。\n");
	fskill = "kuihua-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，使不出"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");
  if( (int)me->query("neili") < 100 )
    return notify_fail("你的真气不够！\n");
  msg =  HIM "$N" HIM "默运葵花心法，身形变得奇快无比，接连向$n"
              HIM "攻出数招！\n" NOR;
  message_combatd(msg, me,target);

	sword_lvl = me->query_skill(sskill,1)/15; 
	count = (me->query_skill(sskill,1)-1)/100; 

  for(i=0;i<count+2;i++)
  {
    if (flag == 1) target = offensive_target(me);
    if (!objectp(target)) break;
     me->add_temp("apply/attack",sword_lvl);
    me->add_temp("bixie_hit", 1);
    if (i) me->set_temp("action_flag",1);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
		me->add_temp("bixie_hit", -1);
    me->set_temp("action_flag",0);
  }
  me->add_temp("apply/attack",-i*sword_lvl);
  
  me->add("neili", -50);
  me->start_busy(1);

  if(flag!=1 && !target->is_fighting(me)) target->fight_ob(me);
  return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
  write(@HELP

	使用功效：
		连续出手

	出手要求：
		葵花心法100级
		辟邪剑法101级
		内力100
HELP
  );
  return 1;
}

