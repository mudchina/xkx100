// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#define PNAME "「绝剑」"

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int extra;
	int count;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

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
 
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail(PNAME"必须使剑出手！\n");

	fskill = "linji-zhuang";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(fskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的真气不够！\n");

	extra = me->query_skill(sskill,1) *2/ 15;
 
        msg = HIY "$N使出回风拂柳剑绝技「连环三绝剑」，一招连环三剑，手中的"+ weapon->name()+  HIY"闪电般攻出第一剑！\n" NOR;
        message_combatd(msg, me);

        me->add_temp("apply/attack", extra*4);

        msg = HIC "只见$N右手一抖，"+ weapon->name()+ HIC"划向$n"HIC"的左肩！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道剑气"HIR"击向$n"HIR"周身，$n"HIR"只觉得全身气脉通道阻塞，真气立受干挠！\n"NOR;   
        message_combatd(msg, me, target);
        target->start_busy(2);
        }
        msg =  HIW "$N凌空一劈，"+ weapon->name()+ HIW"削向$n"HIW"的右肩！" NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道剑气"HIM"扫中$n"HIM"的身上,$n"HIM"只觉得全身一阵急痛！\n"NOR;   
                message_combatd(msg, me, target);
        target->receive_damage("jing",extra*2,me);
        target->receive_wound("jing",extra*2,me);
        }
        msg = HIY "$N长啸一声，聚功力于左手，使出剑法的最高境界--绝剑，朝$n"HIY"的胸前劈去！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道剑气"HIB"扫中$n"HIB"的章门穴,$n"HIB"只觉得全身内力提不起来了！\n"NOR;   
        message_combatd(msg, me, target);
        target->add("neili",-extra*4);
        }
        me->add("neili", -300);
        me->add_temp("apply/attack", - extra*4);
        me->start_busy(3);

        return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		连续出手三招
		分别考验双方的轻功、内功和武功修为

	出手要求：
		临济十二庄80级
		回风拂柳剑100级
		内力300
HELP
	);
	return 1;
}
