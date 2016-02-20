// jianzhang.c  天山奇峰
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "「天山奇峰」"
string *desc = ({
HIW"\n                  ^长空雷隐！^          \n" NOR,
HIY  "                ^^^山风凛冽！^^^       \n" NOR,
RED  "             ^^^^^^回光幻电！^^^^^^  \n" NOR,
HIM  "          ^^^^^^^^^冰河开冻！^^^^^^^^^ \n" NOR,
HIC  "       ^^^^^^^^^^^^天山雪崩！^^^^^^^^^^^^ \n" NOR,
});
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,i;
        int staff_level;
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
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");

	fskill = "huagong-dafa";
	bskill = "staff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"修为不够，无法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	msg = HIY "$N使出星宿派绝技「天山奇峰」，身法陡然加快。\n"NOR;
	message_combatd(msg,me,target);
  staff_level=me->query_skill(bskill);
  for (i=0;i<5;i++)
  {
		if (flag == 1) target = offensive_target(me);
		if (!objectp(target)) break;
		msg = desc[i];
		message_combatd(msg,me,target);
		me->add_temp("apply/attack",staff_level/20);
		me->add_temp("apply/damage",staff_level/20);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->add_temp("apply/attack",-staff_level/20*i);
	me->add_temp("apply/damage",-staff_level/20*i);
	me->add("neili", -250);
	me->start_busy(3);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

        使用功效：
                连续出手数杖

        出手要求：
                化功大法100级
                天山杖法100级
                内力修为300
                内力500
HELP
        );
        return 1;
}