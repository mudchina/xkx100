// jingang.c 金刚拳 大金刚神通
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "「大金刚神通」"
void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object weapon;	
	string msg;
	int d_count, count, qi, maxqi, skill;
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

//空手兵器均可

	fskill = "hunyuan-yiqi";
	bskill = "cuff";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}
	
	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"的修为不够，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 150 )
		return notify_fail("你的"+to_chinese(bskill)+"还不到家，无法使用"+PNAME+"。\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail( HIG"你已经在八仙醉打了。\n"NOR);

	if( (int)me->query_temp("powerup"))
		return notify_fail( HIG"你已经运起内功加力了，没有更多的内力使用大金刚神通。\n"NOR);

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的内力还不够！\n");

	msg = HIY "$N"HIY"使出大金刚拳的绝技「大金刚神通」，臂力陡然增加！\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill(bskill, 1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{
		if( (int)me->query_temp("jingang") ) 
	  	return notify_fail( HIG"你已经在运功中了。\n"NOR);
		message_combatd(msg, me, target);
		
		me->add_temp("apply/strength", count * 2);	
		me->add_temp("apply/dexerity", 0-d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -150);
	}
	else
	{
		msg =HIR "$N拼尽毕生功力使出了大金刚拳的终极绝技，全身骨骼一阵爆响，欲与敌人同归于尽！\n" NOR;
		message_combatd(msg, me, target);
		me->add_temp("apply/strength", count * 8);
		me->add_temp("jingang", 1);
		me->set("jiali",me->query("jiali")*3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->set("jiali",me->query("jiali")/3);
		me->add_temp("jingang", -1);
		me->add_temp("apply/strength", - count * 8);
		me->set("neili",0);
		me->add("max_neili",-10);

		msg=HIR"$N用尽了最后一点气力，喷出一口鲜血，一头栽倒在地！\n"NOR;
		message_combatd(msg, me, target);

		me->set("jing",0);
		me->set("qi",0);

		me->unconcious();
	}
	return 1;
}

void remove_effect(object me, int aamount, int damount)
{
	if ( (int)me->query_temp("jingang") ) 
	{
		me->add_temp("apply/strength",-aamount);
		me->add_temp("apply/dexerity", damount);
		me->delete_temp("jingang");
		tell_object(me,HIY"你的大金刚神通运行完毕，将内力收回丹田。\n"NOR);
		me->start_busy(random(4));
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		降低自己的防御力，大力提升自己的攻击力
		重伤之际更可把攻击力提高到极致，但出招后会晕倒

	出手要求：
		混元一气功60级
		基本拳法150级
		内力500
HELP
	);
	return 1;
}

