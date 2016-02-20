// luohuaqiuge.c 落花秋歌
// Last Modified by suncity on May.26 2002

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define PNAME "［落花秋歌］"
int perform(object me, object target)
{
	string msg;
	int skl_me, skl_you, extra_me, extra_you, i, damage;
	int FLAG=0;
	object you,ob,*obs,weapon;
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
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");

	fskill = "honghua-shengong";
	bskill = "blade";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不能使用"+PNAME+"。\n");

	if( (int)me->query("max_neili") < 800 )
		return notify_fail("你的内力修为不够，不能使用绝招。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力不够，不能使用绝招。\n");

	if(pointerp(obs=me->query_team()) )
	{
		FLAG=1;
		for(i=0;i<sizeof(obs);i++)
		{
			if(obs[i] == me) continue;
			if(!obs[i]) {FLAG=0;continue;}
			if(environment(obs[i]) != environment(me))
				{FLAG=0;continue;}
			if(!obs[i]->query_skill("luohua-jian"))
				{FLAG=0;continue;}
			if(obs[i]->query_skill("luohua-jian",1) < 100)
				{FLAG=0;continue;}
			if (!objectp(ob = obs[i]->query_temp("weapon"))
				|| (string)ob->query("skill_type") != "sword")
				{FLAG=0;continue;}
			if(obs[i]->query_skill_mapped("sword")!="luohua-jian")
				{FLAG=0;continue;}
			if(obs[i]->query("max_neili") < 800 )
				{FLAG=0;continue;}
			if(obs[i]->query("neili") < 500 )
				{FLAG=0;continue;}
		}
		if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("blade");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/10;
	if(FLAG)
	{
//		if(target->query("owner"))
		if(obs[0]==me) you=obs[1]; else you=obs[0];
		if(!userp(target))
		if (!target->accept_hit(me) || !target->accept_hit(you))
			return notify_fail("本门任务怎可假别人之手完成。\n");
		skl_you=(int)you->query_skill("sword");
		extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str();

		msg = HIR"$N暴喝一声，"HIG"“小苑莺歌歇”"HIR"－－手中"+weapon->name()+HIR"圈转，啸音反强，刀光啸音浑然一体，滚向$n！\n"NOR;
		msg +=HIY"“长门蝶舞多”"HIR"－－"+you->name()+HIR"手中"+ob->name()+HIR"化做流云，飘向$n！\n"NOR;
		message_combatd(msg, me, target);
		me->add_temp("apply/attack",(skl_you+skl_me)/5);
		me->add_temp("apply/damage",(extra_you+extra_me));
		you->add_temp("apply/attack",(skl_you+skl_me)/5);
		you->add_temp("apply/damage",(extra_you+extra_me));
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);

		msg = HIY"“眼看春又去”"HIR"－－$N纤腰摆动，手中"+weapon->name()+HIR"似流水般袭向$n！\n"NOR,
		msg +=HIG"“翠辇不曾过”"HIR"－－"+you->name()+HIR"手中"+ob->name()+HIR"似重逾千斤，磕向$n！\n"NOR,
		message_combatd(msg, me, target);
		COMBAT_D->do_attack(you,target, you->query_temp("weapon"), TYPE_REGULAR,msg);
		you->add_temp("apply/attack",-(skl_you+skl_me)/5);
		you->add_temp("apply/damage",-(extra_you+extra_me));
		me->add_temp("apply/attack",-(skl_you+skl_me)/5);
		me->add_temp("apply/damage",-(extra_you+extra_me));
		me->start_busy(random(4));
		you->start_busy(random(3));
                me->add("neili",-400);
                you->add("neili",-400);
	}
	else return notify_fail("你想使落花秋歌，可是没人很好配合，没使出来。\n");
	return 1;
}
int help(object me)
{
	write(WHT"\n秋歌七刀之落花秋歌"NOR"\n");
	write(@HELP

	使用功效：
		大增己方攻击力和防御力，共同出手两招

	出手要求：
		红花神功100级
		秋歌七刀100级
		内力修为800
		内力500
		必须有伙伴组队配合
	伙伴要求：
		红花神功100级
		落花十三剑100级
		内力修为800
		内力500
HELP
	);
	return 1;
}

