// he.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/he") &&
  !me->query("can_perform/quanzhen-jian/he") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的外功中没有这种功能。");

	if( !objectp(target) ) target = offensive_target(me);
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	  !living(target) || target->query_temp("noliving") )
		return notify_fail("［双剑合璧］只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");
        if(me->query("neili")<400)
                return notify_fail("你的内力不够使用双剑合璧。\n");
	if( !me->query_temp("murong/xingyi") )
	{
		if( (int)me->query_skill("xiantian-qigong", 1) < 100 )
			return notify_fail("你的先天气功不够娴熟，不能用双剑合璧。\n");
		if( (int)me->query_skill("quanzhen-jian", 1) < 100 )
			return notify_fail("你的全真剑法不够娴熟，不能用双剑合璧。\n");
	}
	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 400)
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("yunv-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-jian",1) < 100)
				{FLAG=0;continue;}
			if(obs[i]->query_skill("yunv-xinfa",1) < 100)
				{FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="yunv-jian")
				{FLAG=0;continue;}
			if(obs[i]->is_busy())
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("sword");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
	if(obs[0]==me) you=obs[1]; else you=obs[0];
	if(me->query("gender")!="男性" || you->query("gender")!="女性")
		return notify_fail("双剑合璧必须男使全真剑法，同时女使玉女剑法方能激发。\n");
  	if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("本门任务怎可假别人之手完成。\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();
		msg = HIY + "$N施展出全真剑法的厉害剑招，" + HIG + you->name()+"施展出玉女剑法的险恶家数，\n" + HIR +
		 "双剑合璧，威力立时大得惊人，$n无法齐挡双剑击刺，向後急退，嗤嗤两声，身上两剑齐中！\n"NOR ;

		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
                you->add("neili",-300);
                me->add("neili",-300);
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
		me->start_busy(2+random(2));
		you->start_busy(2+random(2));
    if (target->query("qi") > 0 && target->query("jing") > 0)
    {
    	msg = HIC"亏得$n闪避得宜，剑锋从两胁掠过，只划破了他衣服，但已吓出了一身冷汗。\n"NOR;
			message_combatd(msg, me, target);
		}
	}
	else
	{
//		msg =HIY"$N"+HIG"欲与"HIY+you->name()+HIG"施展双剑合璧，可是她没法和你配合。\n" + NOR;
		msg =HIY"$N欲施展双剑合璧，可是没有合适的人一起配合。\n" + NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}
int help(object me)
{
	write(WHT"\n全真剑法之双剑合璧"NOR"\n");
	write(@HELP

	使用功效：
		大增己方攻击力和防御力，共同出手一招

	出手要求：
		男性
		先天气功100级
		全真剑法100级
		内力100
	伙伴要求：
		女性
		玉女心法100级
		玉女剑法100级
		内力100
HELP
	);
	return 1;
}

