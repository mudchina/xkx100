#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
#include <xiaoyao.h>

inherit F_SSERVER;
#define PNAME "「" HIR "破神诀" NOR "」"
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	int ap, dp, p;
	int lv, cost_neili;
	int mark = 0;
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

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail(PNAME "只能空手施展。\n");

	fskill = "bahuang-gong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(fskill)+"火候不够，难以施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够，难以施展"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(bskill)+"等级不够，难以施展"+PNAME+"。\n");

	if (userp(me) && (int)me->query("con", 1) < 20)
		return notify_fail("你先天根骨不够高，难以施展" PNAME "。\n");
		
	if (me->query("max_neili") < 3000)
		return notify_fail("你的内力修为不足，难以施展" PNAME "。\n");

	if (me->query_skill_mapped("force") != fskill)
		return notify_fail("你没有激发八荒六合唯我独尊功，难以施展" PNAME "。\n");

	if (me->query("neili") < 800)
		return notify_fail("你现在真气不足，难以施展" PNAME "。\n");

	msg = HIR "$N" HIR "将八荒六合唯我独尊功提运至极限，全身真气迸发，呼的一掌"
              "向$n" HIR "头顶猛然贯落。\n" NOR;

	ap = me->query_skill("force", 1) + me->query_skill(bskill);
	dp = target->query_skill("force", 1) + target->query_skill("parry");

	if (target->query("shen") * me->query("shen") < 0 ||  userp(target))
		ap += ap / 10;
	if (fam_type(me)=="lingjiu") ap += ap/5;

	if (ap /2 + random(ap) +10 > dp)
	{
		damage = 0;
		if (me->query("max_neili") > target->query("max_neili") * 2)
		{
                        msg += HIR "顿时只听“噗”的一声，$N" HIR "一掌将$n"
                               HIR "头骨拍得粉碎，脑浆四溅，当即瘫了下去。\n"NOR;
			msg += "( $n" + eff_status_msg(0) + " )\n";

		 target->receive_wound("jing",target->query("eff_jing"),me);
		 target->receive_wound("qi",target->query("eff_qi"),me);
 		 me->add("neili", -100);
		 me->start_busy(1);
	 	 message_combatd(msg, me, target);
		 target->unconcious();
	 	 return 1;
		} else
		{
	 		me->add("neili", -300);
/*			damage = ap *2/3;
			damage += random(damage/2);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage *9/10, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);*/
			damage = ap;
			damage += random(damage);

			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage / 2, me);
			target->receive_damage("jing", damage / 4, me);
			target->receive_wound("jing", damage / 8, me);
			p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

			msg += HIR "$n" HIR "慌忙抵挡，可已然不及，$N"
                               HIR "掌劲如洪水般涌入体内，接连震断数根"
                                   "肋骨。\n"NOR;
			msg += "( $n" + eff_status_msg(p) + " )\n";
			
		}
		me->start_busy(3);
	} else
	{
		msg += CYN "$p" CYN "见$P" CYN "掌劲澎湃，决计抵挡不"
                       "住，当即身子向后横丈许，躲闪开来。\n" NOR;
		me->add("neili", -200);
		me->start_busy(4);
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
		伤敌精、气

	出手要求：
		先天根骨20
		八荒六合唯我独尊功200级
		天山六阳掌手200级
		基本掌法200级
		最大内力3000
		内力800
HELP
	);
	return 1;
}