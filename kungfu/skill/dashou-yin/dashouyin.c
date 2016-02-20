// dashouyin.c 大手印
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
#define PNAME "「大手印」"
int perform(object me, object target)
{
	string msg, dodge_skill;					  
	int damage, jiali, attack, defense, p;
	object armor;
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
		
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手使用「大手印」！\n");

	fskill = "longxiang";
	bskill = "hand";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	if( (int)me->query_skill(fskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(fskill)+"等级不够，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(sskill)+"还不够娴熟，无法使用"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 120 )
		return notify_fail("你的"+to_chinese(bskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if (me->query_skill_prepared("hand") != "dashou-yin" ||
			me->query_skill_mapped("hand") != "dashou-yin" ||
			me->query_skill_mapped("parry") != "dashou-yin")
			return notify_fail("你必须用基本手法和基本招架激发大手印！\n");
	}
	if( (int)me->query_str() < 35 )
		return notify_fail("你的膂力不够强，不能使用"PNAME"！\n");
	if( (int)me->query("max_neili") < 1200 )
		return notify_fail("你的内力修为太弱，不能使用"PNAME"！\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("你的内力太少了，无法使用出"PNAME"！\n");
	if( (int)target->query_condition("dashouyin"))
		return notify_fail("对方早已身中"PNAME"绝技了！\n");   
	

	jiali = me->query("jiali")+1;
	attack = me->query("combat_exp")/1000;
	attack += me->query_skill(bskill);
	attack += me->query("neili")/5;
	defense = target->query("combat_exp")/1000;
	defense += target->query_skill("dodge");
	defense += target->query("neili")/7;
	attack = (attack+random(attack+1))/2;
	
	damage = me->query_skill(bskill, 1)/40 * jiali;
	if(damage > 1500) damage = 1500;
	
	message_combatd(BLU"\n$N"BLU"突然面色怪异，低声默念密宗真言，双臂骨节一阵爆响，\n猛然腾空而起，伸手向$n"BLU"胸前按去，好一式密宗「大手印」！\n"NOR,me,target);
 
	if( attack > defense )
	{ 
		if( objectp(armor = target->query_temp("armor/cloth")) &&
			armor->query("armor_prop/armor") < 200 &&
			damage > 500)
		{
			message_combatd( HIY"只见这斗大的手印正好印在$N的$n"HIY"上，越变越大，竟将它震得粉碎，裂成一块块掉在地上！\n"NOR, target, armor);
			armor->unequip();
      seteuid(getuid());
      piece = new("/clone/misc/piece");
      piece->set_name( "破碎的"+armor->query("name"), ({armor->query("id"),"piece"}) );
      piece->move(environment(target));
      destruct(armor);
			target->reset_action();
		}
		tell_object(target, RED"你只觉得霍的胸口一阵剧痛，已经被拍中了前胸！\n"NOR);
		target->apply_condition("dashouyin", 1+(me->query_str()/8));
		target->receive_damage("qi", damage,  me); 
		target->receive_wound("qi", damage/4, me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		msg = damage_msg(damage, "内伤");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		message_combatd(msg, me, target);
		me->add("neili", -jiali);
	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_combatd(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
	}
	me->add("neili", -200);
	me->start_busy(2+random(2));		
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
        write(@HELP

	使用功效：
		损害对手精气和气血
		致对手大手印毒

	出手要求：
		龙象般若功120级
		密宗大手印120级
		基本手法120级
		后天膂力35
		内力800
		内力修为1200
HELP
        );
        return 1;
}
 
