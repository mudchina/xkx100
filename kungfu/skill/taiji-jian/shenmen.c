// shenmen.c 「神门十三剑」
// Last Modified by winder on Aug. 18 2002

#include <combat.h>
#include <ansi.h>
inherit F_SSERVER;
#define PNAME "「神门十三剑」"
int perform(object me, object target)
{
        mapping prepare;
        string msg, result;
        string attack_skill, dodge_skill, parry_skill;
        int ap, dp, pp, damage, level;
	object weapon, weapon2;
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
		
	if( !objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能使出「神门十三剑」？！\n");

	fskill = "taiji-shengong";
	bskill = "sword";
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

	if( (int)me->query_skill(sskill, 1) < 140 )
		return notify_fail("你的"+to_chinese(sskill)+"修为还不够，难以施展"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 125 )
		return notify_fail("你的"+to_chinese(bskill)+"还不够娴熟，无法使用"+PNAME+"。\n");

	if( me->query_skill_mapped("force") != fskill )
		return notify_fail("你所用的内功与「神门十三剑」心法相悖！\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if( me->query_skill("sword", 1) < 125 )
			return notify_fail("你的剑法修为还不够，难以施展「神门十三剑」！\n");
		if( me->query_skill("taiji-jian", 1) < 125 )
			return notify_fail("你的太极剑法修为还不够，难以施展「神门十三剑」！\n");
	}

	if( me->query("neili") <= 200 )
		return notify_fail("你的内力不够，难以施展「神门十三剑」！\n");

	if( me->query("qi") <= 400 )
		return notify_fail("你的体力有限，难以施展「神门十三剑」！\n");

	msg = "\n$N运剑如风似电，指尖抖动，$w於瞬息之间刺了十三下，十三点寒星似乎同时扑出，落点不失厘毫，每一剑都刺向$n手腕“神门穴”！\n"NOR;

  ap = me->query_skill(bskill,1);
  dp = target->query_skill("dodge",1)/4;

	if( random(ap) < dp )
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg();
	}
	else
	{
		pp = target->query_skill("parry",1)/4;              

		weapon2 = target->query_temp("weapon");
		if( random(ap) < pp )
		{
			parry_skill = target->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
			msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
		}
		else 
		{
			if( objectp(weapon2) )
			{
				msg += HIR"$n只觉得“神门穴”上一阵酸麻，手指无力，"
				"$W"HIR"拿捏不稳，抛在地下！\n"NOR;                        
				weapon2->unequip();
				weapon2->move(environment(target));
			}
			else msg += HIR"$n只觉得“神门穴”上一阵酸麻，$W再也使不出半点力道。\n"NOR;

			level = me->query_skill("taiji-jian", 1);
			target->reset_action();
			target->start_busy(1+random(level/100));
			if( !target->query_temp("acupoint/shenmen") )
			{
				level = target->query_str() * level / 980;
				target->add_temp("apply/strength", -level); 
				target->set_temp("acupoint/shenmen", "stabbed");
				target->start_call_out( (: call_other, __FILE__, "remove_effect", target, level :), me->query_skill("force")/10 );
				if( wizardp(me) ) tell_object(me, sprintf("\ndrop bili: %d", level));
			}

			damage = 50+random(29);
			target->receive_damage("qi", damage, me);
			target->receive_wound("qi", damage/2, me);

			result = COMBAT_D->damage_msg(damage, "刺伤");
			msg += result;

			result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
				(int)target->query("max_qi"));
			msg += "( $n"+result+" )\n";
		}
	}

	me->add("neili", -80);
	me->receive_damage("qi", 40);
	me->start_busy(1);

	msg = replace_string( msg, "$l", "神门穴" );
	msg = replace_string( msg, "$w", weapon->name() );

	prepare = target->query_skill_prepare();
	if( !prepare ) prepare = ([]);

	switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[random(2)]; break;
	}

        if( objectp(weapon2) )
		msg = replace_string( msg, "$W", weapon2->name() );
	else switch( attack_skill )
	{
		case "finger" :	msg = replace_string( msg, "$W", "手指" );
				break;
		case "cuff" :	msg = replace_string( msg, "$W", "拳头" );
				break;
		case "strike" :	msg = replace_string( msg, "$W", "手掌" );
				break;
		case "claw" :	msg = replace_string( msg, "$W", "手爪" );
				break;
		default :	msg = replace_string( msg, "$W", "" );
				break;
	}

        message_combatd(msg, me, target);
        return 1;
}

void remove_effect(object me, int amount)
{
  message_combatd(HIG"$N活动了一下手腕，手上渐渐又有了力气。\n"NOR, me);
	me->add_temp("apply/strength", amount);
	me->delete_temp("acupoint/shenmen");
}

string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
                这“神门十三剑”共有一十三记招数，每记招式各不相同，但所刺之处，
全是敌人手腕的“神门穴”。

	出手要求：
		激发太极神功
		基本剑法125级
		太极剑法125级
		太极神功100级
		内力200
		气血400
HELP
	);
	return 1;
}

