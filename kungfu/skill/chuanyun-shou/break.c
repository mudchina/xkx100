// break -「抱月摘星」
// Last Modify by sir 5/17/2001
 
#include <ansi.h>
#define PNAME "「抱月摘星」"
inherit F_SSERVER;
 
int perform(object me,object target)
{
	string msg;
	object weapon,  target_w;
	int ap, dp, equip;	
	object piece;
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
 
//	if (objectp(weapon = me->query_temp("weapon")))
//		return notify_fail("你必须空手运功。\n");
	// 兵器空手均可

	fskill = "baiyun-xinfa";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 80 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使出"+PNAME+"。\n");

	if( me->query("neili") < 800 )
		return notify_fail("你的内力不够，无法运功！\n");
 
	if( me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够，无法运功！\n");
 
	msg = HIC"$N"HIC"沉肩滑步，自丹田中升起一股阴柔之气顺着血脉经络传至双手劳宫穴，接着这股阴柔之气就激射而出，喷向$n"HIC"手中的兵刃！\n"; 

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 2;
	if( dp < 1 ) dp = 1;
	target_w = target->query_temp("weapon");

	if (target->query_temp("weapon") ||
		target->query_temp("secondary_weapon"))
	{ 
		if( random(ap) > dp )
		{	
			me->add("neili",-400);
			msg += HIW"却只听得一阵丁当作响，兵器碎片丢了一地！\n"NOR;
			target_w->unequip();
			target->reset_action();
      seteuid(getuid());
      piece = new("/clone/misc/piece");
      piece->set("long", "一堆兵器碎片。\n");
      piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      piece->move(environment(target));
      destruct(target_w);
			me->start_busy(random(2));
		}
		else 
		{
			msg += "可是$p急急拆招，躲了开去。\n" NOR;
			me->add("neili",-200);
			me->start_busy(2);
		}   
		message_combatd(msg, me, target);
		if(!target->is_fighting(me)) target->fight_ob(me);
		return 1;
	}
	return notify_fail(target->name() + "目前是空手，没什么可以震碎的。\n");
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		毁坏对方兵器

	出手要求：
		白云心法100级
		穿云手80级
		内力1000
HELP
	);
	return 1;
}

