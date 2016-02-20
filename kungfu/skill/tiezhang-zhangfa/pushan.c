// pushan.c 铁掌掌法 「铁蒲扇掌」

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
#define PNAME "「铁蒲扇掌」"
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
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中没有这种功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能对战斗中的对手使用。\n");
		
	if( me->query_temp("weapon") )
		return notify_fail("你必须空手才能使用铁蒲扇掌！\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你现在内力修为不足，使不出铁蒲扇掌招！\n");

	if( (int)me->query("neili") < 1200 )
		return notify_fail("你现在内力不足，使不出铁蒲扇掌绝招！\n");

	fskill = "guiyuan-tunafa";
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
		return notify_fail("你的"+to_chinese(fskill)+"不够熟练，不能使"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(sskill)+"不够熟练，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，使不出"+PNAME+"。\n");

	if( me->query_temp("tiezhang_pushan") )
		return notify_fail("你刚使完铁蒲扇掌绝招，目前气血翻涌，无法再次运用！\n");

	msg = RED"\n$N身子半侧，左掌直推而出，使的正是$N铁掌掌法中刚猛无俦的铁蒲扇掌，掌风夹杂一股热浪直扑$n而去！\n"NOR;	
	me->set_temp("tiezhang_pushan", 1);
	if (random(me->query_skill("force")) > target->query_skill("force") /4 )
	{
		me->start_busy(1);
		target->start_busy(1); 
		me->add("neili", -800);
		me->receive_damage("jing", 10);
		damage = (int)me->query_skill(bskill, 1);
		damage = damage*2 + random(damage);
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		call_out("perform2", 2, me, target, p);
	} 
	else
	{
		me->start_busy(2);
		target->start_busy(1);
		me->add("neili", -300);
		tell_object(target, HIY"你但觉一股热风扑面而来，风势强劲已急，中人窒息，大觉不妙，连忙跃开数尺。\n" NOR);
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
	
	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
		message_combatd("$N已经不能再战斗了！\n", target);
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	if( me->query("neili") < 400 )
	{
		message_combatd("$N待要发出第二掌，却发现内力不够了！\n", me);
		call_out("remove_effect", me->query_con()/6, me);
		return 1;
	}
	
	msg = RED"\n$N左掌劲力未消，右掌也跟着劈出，劲力相叠，铁蒲扇掌狂飙般涌向$n！\n"NOR;	
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill("strike", 1) > 199 )
	{
		me->start_busy(1);
		target->start_busy(1);
		me->add("neili", -200);
		me->receive_damage("jing", 20);
		damage = (int)me->query_skill("strike", 1);		
		damage = damage*3 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg += damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";		
		call_out("perform3", 2, me, target, p);
	} 
	else 
	{
		me->start_busy(2);
		me->add("neili", -200);
		tell_object(target, HIY"你喘息未定，又觉一股劲风扑面而来，脚尖疾点，跃开数尺避开。\n" NOR);
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

	if (!objectp(target) || target->is_ghost() || 
		environment(target)!=environment(me) || 
		!living(me) || me->query_temp("noliving") || me->is_ghost())
	{
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	if( !living(target) || target->query_temp("noliving") )
	{
		message_combatd("$N已经不能再战斗了！\n", target);
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	if( me->query("neili") < 700 )
	{
		message_combatd("$N待要发出第三掌，却发现内力不够了！\n", me);
		call_out("remove_effect", me->query_con()/4, me);
		return 1;
	}
	msg = RED"\n$N双腿一蹬，双掌相并向前和身扑出，$n连同身前身后的方圆数丈全在铁蒲扇掌劲力笼罩之下！\n"NOR;
	if(random(me->query_skill("force")) > target->query_skill("force")/4 &&
		me->query_skill("strike", 1) > 249 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		me->add("neili", -300);
		me->receive_damage("jing", 30);
		damage = (int)me->query_skill("strike", 1);		
		damage = damage*5 + random(damage)*2;
		if(me->query("neili") > target->query("neili")*2 )
			damage += random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage/2,me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
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
	me->delete_temp("tiezhang_pushan");
	tell_object(me, HIC"\n你经过一段时间调气养息，又可以使用铁蒲扇掌绝招了。\n"NOR); 
}

int help(object me)
{
	write(WHT"\n铁掌掌法之铁蒲扇掌："NOR"\n");
	write(@HELP

	使用功效：
		连续出手三掌，本式由内力推动，刚猛无俦

	出手要求：
		归元吐纳法150级
		铁掌掌法150级
		内力修为1500
		内力1200
HELP
	);
	return 1;
}

