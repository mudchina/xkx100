// ju.c 三花聚顶
// Last Modified by winder on Mar. 10 2000
 
#include <ansi.h>
 
inherit F_SSERVER;
#define PNAME "「三花聚顶」"
int perform(object me,object target)
{
	string msg;
	object weapon,  target_w, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;
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

	if( me->query_temp("htz_ju"))
		return notify_fail(HIR"你已经在运「三花聚顶」了。\n"NOR);
		
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你必须空手运功。\n");

	fskill = "xiantian-qigong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够, 不能使出"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 135 )
		return notify_fail("你的"+to_chinese(sskill)+"等级不够, 不能使出"+PNAME+"。\n");

	if( me->query("neili") < 800 )
		return notify_fail("你的内力不够，无法运功！\n");

	if( me->query("max_neili") < 1000 )
		return notify_fail("你的内力修为不够，无法运功！\n");

	skill = me->query_skill(bskill,1);
 
	msg = HIC "$N"HIC"猛地提起内力，一股"HIB"青气"HIC"直冒上脸前来，随即大喝一
声，聚气于掌，一掌劈面而下，「三花聚顶」！\n"NOR;

	ap = me->query("combat_exp");
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-600);
		target_w = target->query_temp("weapon");
		msg += HIC"$N内力充满全身，守得更是沉稳！\n"NOR;

		if (target->query_temp("weapon") ||
			target->query_temp("secondary_weapon"))
		{
			target_w->unequip();
			target->reset_action();
			msg += HIY"却只听得一阵丁当作响，兵器碎片丢了一地！\n"NOR;
      	seteuid(getuid());
      	piece = new("/clone/misc/piece");
      	piece->set("long", "一堆兵器的碎片。\n");
      	piece->set_name( target_w->query("name") + "的碎片", ({target_w->query("id"),"piece"}) );
      	piece->move(environment(target));
     		destruct(target_w);
		}
		me->add_temp("apply/attack", -skill/3);
		me->add_temp("apply/dodge", skill/4);
		me->set_temp("htz_ju", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), skill/3);
//		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/3 :));

		me->start_busy(random(2));
	}
	else
	{
		msg += HIC"$n见$N胁下空门大露，疾速抢攻，迫得$N连忙收掌！\n"NOR;
		if(userp(me)) me->add("neili",-600);
		me->start_busy(4);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", a_amount);
	me->add_temp("apply/dodge", -d_amount);
	me->delete_temp("htz_ju");
	tell_object(me, HIY "你的三花聚顶运行完毕，将内力收回丹田。\n"NOR);
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增加自己的攻击力和防护力
		有可能毁坏对方兵器

	出手要求：
		先天气功135级
		昊天掌135级
		内力1000
HELP
	);
	return 1;
}

