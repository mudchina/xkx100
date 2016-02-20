// yunwu.c 衡山剑法 百变千幻衡山云雾十三式
// Last Modified by ahda on Sep.1 2001

#include <ansi.h>
#define PNAME "衡山云雾十三式"
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int qi_wound;
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
		return  notify_fail("你要对谁使用这一绝技？\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("这里不能攻击别人! \n");

  notify_fail("你不能攻击这个人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");		

	if( target->is_busy()||target->query("id")=="gongping zi")
		return notify_fail(target->name()+ "目前正自顾不暇，放胆攻击吧！\n");

	if( userp(me) && (me->query("family/master_id") != "mo da") )
		return notify_fail("你不是莫大的弟子，不能使用绝招！\n");

	fskill = "huiyan-xinfa";
	bskill = "sword";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 180 )
		return notify_fail("你的"+to_chinese(fskill)+"的功力不够不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(sskill)+"修为不够，目前还不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 200 )
		return notify_fail("你的"+to_chinese(bskill)+"根基不够扎实，目前还不能使用"+PNAME+"。\n");

	if((int)me->query_str() < 40)
		return notify_fail("你膂力不够,不能使用这一绝技！\n");

	if((int)me->query("neili") < 500)
		return notify_fail("你内力现在不够，不能使用"PNAME"！\n");

	if((int)me->query("max_neili") < 2500)
		return notify_fail("你的内功修为不够，无法使用衡山云雾十三式！\n");


	msg = HIC"$N手中"+weapon->name()+"寒光陡闪，猛地反刺，直指$n"HIC"胸口。
这一下出招快极，抑且如梦如幻，正是“百变千幻衡山云雾十三式”中的绝招！\n";

	if(random(me->query("combat_exp")/3) > (int)target->query("combat_exp")/4)
	{                                             
		msg += HIY "$p大骇之下，急向后退，嗤的一声，胸口已给利剑割了一道长长的口子，\n衣衫尽裂，胸口肌肉也给割伤了，受伤虽然不重，却已惊怒交集，锐气大失。\n"+ HIR "$P一剑既占先机，后着绵绵而至，一柄薄剑犹如灵蛇，颤动不绝，犹如鬼魅，\n一点点鲜血从长剑间溅了出来。\n" NOR;
		qi_wound = (int)target->query("max_qi",1);
		target->receive_damage("qi", qi_wound/2,me);
		target->receive_wound("qi", qi_wound/2,me);
		target->start_busy(2);
		me->start_busy(3);
		me->add("neili", -500);
	}
	else
	{
		msg += HIM "可是$p看破了$P的企图，身子往后侧闪，堪堪地躲开了$P这一击。\n" NOR;
		me->start_busy(3);
		me->add("neili", -200);
	}
	message_combatd(msg, me, target);
	if(!target->is_killing(me)) target->kill_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP
	
	使用功效：
		严重损伤对方气血
	
	出手要求：
		回雁心法180级
		衡山剑法200级
		基本剑法200级
		内力2500
		后天膂力40
HELP
	);
	return 1;
}

