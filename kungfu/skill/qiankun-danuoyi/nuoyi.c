// nuoyi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "挪移"
int perform(object me, string arg)
{
        string who1, who2;
        object target, victim;
        int damage, lvl, form, skill, i;
        string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/nuoyi") &&
  !me->query("can_perform/qiankun-danuoyi/nuoyi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");
	 
	 if (!me->is_fighting())
   return notify_fail("「乾坤大挪移」只能在战斗中使用。\n");
        if( (int)me->query("max_neili", 1) < 1500 )
		return notify_fail("你的内力修为不足以使用乾坤挪移大法。\n");
        if( (int)me->query("neili", 1) < 1000 )
		return notify_fail("你现在内力太弱，不能使用乾坤挪移大法。\n");


	fskill = "jiuyang-shengong";
	bskill = "dodge";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"未到火候，无法施展"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，小心走火入魔！\n");

	if( !arg )
	{
		target = offensive_target(me);
  	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
			return notify_fail("乾坤大挪移大法只能对战斗中的对手使用。\n");
		form = 1;
	}
	
	else
	{
		target = offensive_target(me);
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
			return notify_fail("乾坤大挪移只对战斗中对手使用。\n");
		victim = present(arg, environment(me));
		if( !victim || !victim->is_character() || victim==me) 
			return notify_fail("你想挪移攻击的对象不在这里。\n");
	   if((victim->name())=="公平子")
	    	return notify_fail("你不可以对公平子使用乾坤大挪移。\n");
  	notify_fail("你不能攻击这个人。\n");
		if (!userp(victim) && !victim->accept_hit(me)) return 0;
		form = 2;
	}

	skill = (int)me->query_skill("dodge", 1);
	lvl = random((int)(skill/30));

	if( form == 1 ) /* 反击对手 */
	{
		msg = CYN "$N默运神功，使出乾坤大挪移大法。\n"NOR;
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/3 )
		{
			target->start_busy(random(3));
			damage = skill/2 + lvl*target->query("jiali",1);
			target->receive_damage("qi", damage,me);
			target->receive_wound("qi", damage/3,me);
			me->add("neili", -damage);
			msg += CYN "将$n"CYN"的内力全数反击回去！\n" NOR;
			if( damage < 20 )
				msg += HIY "结果$n"HIY"受到$N"HIY"的内力反震，闷哼一声。\n"NOR;
			else if( damage < 40 )
				msg += HIY "结果$n"HIY"被$N"HIY"以内力反震，「嘿」地一声退了两步。\n"NOR;
			else if( damage < 80 )
				msg += RED "结果$n"RED"被$N"RED"以内力一震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
			else
				msg += HIR "结果$n"HIR"被$N"HIR"的内力一震，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
		}
		else 
		{
			msg += CYN"可是$n"CYN"内力深厚，丝毫不为所动。\n"NOR;
			me->add("neili", -100);
		}
		message_combatd(msg, me, target);
		return 1;
	}
	else
	{
		write( CYN "你默运神功，使出乾坤大挪移大法，试图将" + target->name() + CYN+"的攻击挪移到" + victim->name() + CYN+"身上。\n"NOR);
		tell_object(victim, CYN"忽然，你发现有一股奇怪的力量向你袭来！\n"NOR);
		me->start_busy(3);
		if(random(me->query("neili")) > target->query("neili")/2)
		{
			write( CYN"哈哈，成功了！\n"NOR);
			if( target == victim)
			{
				tell_object(target, CYN"你身不由己，一招击向自己！\n"NOR);
				message("combatd",CYN+target->name()+"忽然如中魔一般，招招击向自己！\n\n"NOR, environment(me), target);
				for(i = 0; i < lvl; i++)
					COMBAT_D->do_attack(target, victim, target->query_temp("weapon") );
			}
			else
			{
				tell_object(target, CYN"你身不由几，向" + victim->name() + CYN+"扑去！\n"NOR);
				message("vision", CYN"\n" + target->name() + CYN+"忽然向" + victim->name() +CYN+"扑去！\n\n"NOR, environment(me), ({target, victim}) );
					tell_object(victim, CYN"\n" + target->name() + "忽然向你扑来！\n\n"NOR);
				COMBAT_D->do_attack(target,victim,target->query_temp("weapon"));
				if(random(me->query("combat_exp")) >
					(int)victim->query("combat_exp")/2 )
				{
					target->delete("env/combatd");
					victim->delete("env/combatd");
					if(!victim->is_killing(target))
						victim->kill_ob(target);
				}
				else
				{
					tell_object(victim, CYN"你一定神，原来是" + me->name() + CYN+"在捣鬼！\n"NOR);
					tell_object(target, CYN"还好，幸亏"+victim->name()+CYN+"经验老到，没有上当。\n"NOR);
					write( CYN "不好，被" + victim->name() + CYN+"发觉了！\n"NOR);
					if(!victim->is_killing(me))
						victim->kill_ob(me);
				}
				target->start_busy(random(3));
				me->add("neili", -300);
			}
		}
		else
		{
			write( CYN"可惜没成功。\n"NOR);
			tell_object(target, CYN"你强用心神，终于控制住自己。\n"NOR);
			me->add("neili", -100);
		}
		return 1;
	}
}

int help(object me)
{
	write(WHT"\n乾坤大挪移之挪移"NOR"\n");
	write(@HELP

	使用功效：
		nuoyi :  用来反击敌手的攻击。
		nuoyi <他人> :  用来将当前出手人物的攻击挪移到他人身上。
				可以把敌手的攻击挪移给他自身。
	出手要求：
		九阳神功50级
		乾坤大挪移50级
		内力修为1500
		内力1000
HELP
	);
	return 1;
}

