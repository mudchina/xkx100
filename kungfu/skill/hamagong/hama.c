// Last Modified by winder on May. 15 2001
// hama.c 蛤蟆功绝招

#include <ansi.h>
#define PNAME "「蛤蟆功」"
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage, p;
	string msg, dodge_skill;
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
		
	if( me->query_temp("weapon") )
		return notify_fail("你必须空手才能使用「蛤蟆功」！\n");

	fskill = "hamagong";
	bskill = "strike";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(fskill)+"不够熟练，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，使不出"+PNAME+"。\n");
	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你现在内力修为不足，使不出蛤蟆功绝招！\n");
	if( (int)me->query("neili") < 1200 )
		return notify_fail("你现在内力不足，使不出蛤蟆功的绝招！\n");
	if( me->query_temp("hmg_hama") )
		return notify_fail("你刚使完「蛤蟆功」绝招，目前气血翻涌，无法再次运用！\n");

	msg = BLU"\n$N"BLU"身子蹲下，左掌平推而出，使的正是$N"BLU"生平最得意的「蛤蟆功」绝招，掌风直逼$n"BLU"而去！\n"NOR;	
	me->set_temp("hmg_hama", 1);
	if (random(me->query_skill("force")) > target->query_skill("force") /4 )
	{
		me->start_busy(1);
		target->start_busy(1); 
		me->add("neili", -1000);
		me->add("jing", -10);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage*2 + random(damage);
		if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 0, me, target, p);
	} 
	else
	{
		me->start_busy(2);
		target->start_busy(1);
		me->add("neili", -300);
		tell_object(target, HIY"你但觉一股微风扑面而来，风势虽然不劲，然已逼得自己呼吸不畅，知道不妙，连忙跃开数尺。\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		call_out("remove_effect", me->query_con()/6, me);
	}
	message_combatd(msg, me, target); 
	return 1;
}

int perform2(object me, object target, int p)
{
	int damage;
	string msg, dodge_skill;
	string bskill;

	bskill = "strike";
	if (!me->query_skill("strike"),1) bskill = "parry";
	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
  	call_out("remove_effect", me->query_con()/6, me);
		return notify_fail("对手已经不能再战斗了。\n");
	}
	if( (int)me->query("neili", 1) < 500 )
	{
		call_out("remove_effect", me->query_con()/6, me);
		return notify_fail("你待要再发一掌，却发现自己内力不够了！\n");
	}
	msg = BLU"\n$N左掌劲力未消，右掌也跟着推出，功力相叠，「蛤蟆功」掌风排山倒海般涌向$n！\n"NOR;	
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill(bskill, 1) > 150 )
	{
		me->start_busy(1);
		target->start_busy(1);
		me->add("neili", -200);
		me->add("jing", -20);		
		damage = (int)me->query_skill(bskill, 1);		
		damage = damage*3 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("eff_qi");
		msg += damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";		
		call_out("perform3", 0, me, target, p);
	} 
	else 
	{
		me->start_busy(2);
		me->add("neili", -200);
		tell_object(target, HIY"你喘息未定，又觉一股劲风扑面而来，连忙跃开数尺，狼狈地避开。\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		call_out("remove_effect", me->query_con()/4, me);
	}
	message_combatd(msg, me, target); 
	return 1;
}

int perform3(object me, object target, int p)
{
	int damage;
	string msg, dodge_skill;
	string bskill;

	bskill = "strike";
	if (!me->query_skill("strike"),1) bskill = "parry";
	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
	call_out("remove_effect", me->query_con()/4, me);
	return notify_fail("对手已经不能再战斗了。\n");
	}
	if( (int)me->query("neili", 1) < 700 )
	{		
		call_out("remove_effect", me->query_con()/4, me);
		return notify_fail("你待要再发一掌，却发现自己内力不够了！\n");
	}
	msg = BLU"\n$N双腿一登，双掌相并向前猛力推出，$n连同身前方圆三丈全在「蛤蟆功」劲力笼罩之下！\n"NOR;	
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill(bskill, 1) > 199 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -300);
		me->add("jing", -30);		
		damage = (int)me->query_skill(bskill, 1);		
		damage = damage*5 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("eff_qi");
		msg += damage_msg(damage, "瘀伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	else 
	{
		me->start_busy(4);
		target->start_busy(1);
		me->add("neili", -300);
		target->add("jing", -100);
		tell_object(target, HIY"你用尽全身力量向右一纵一滚，摇摇欲倒地站了起来，但总算躲开了这致命的一击！\n" NOR);
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
	}
	call_out("remove_effect", me->query_con()/2, me);
	message_combatd(msg, me, target); 
	return 1;
}

void remove_effect(object me)
{
	if (!me) return;
	me->delete_temp("hmg_hama");
	tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用「蛤蟆功」绝招了。\n"NOR); 
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		刚猛无俦的连续三掌

	出手要求：
		蛤蟆功150级
		基本掌法100级
		内力修为2000
		内力1200
HELP
	);
	return 1;
}

