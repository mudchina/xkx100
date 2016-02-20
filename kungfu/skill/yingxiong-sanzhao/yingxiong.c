// yingxiong.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "盖世英雄"
int perform(object me, object target)
{
	int level;
	string msg;
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
		
		//兵器空手均可
		
	if( me->query("gender") != "男性" && !wizardp(me))
		return notify_fail("象你这副娘娘腔，也许练“绝世风姿”恐怕更合适点吧。\n");

	fskill = "dulong-dafa";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的内力不足，恐怕没法逞英雄了。\n");

	if( me->query_temp("shenlong/yingxiong") )
		return notify_fail("你已经在大摆英雄的谱了，还不够啊？\n");

	level = me->query_cor()/3;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cor() < random(me->query_cor() * 2) )
	{
		message_combatd(HIY"$N"HIY"越斗越是凶猛，激斗中仰天大吼一声：“盖世英雄！！”，一股豪气自$N心中升起，顿时更是凶悍起来。\n" NOR, me, target);
		me->set_temp("shenlong/yingxiong", 1);
		me->add_temp("apply/courage", level);
		target->start_busy(random(3)+1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, level:), 30);
	}
	else
	{
		message_combatd(HIG"激斗中的$N冲着$n大喊：“盖世。。。”，语意未了，就被$n迫得手忙脚乱。\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object me, int level)
{
	me->delete_temp("shenlong/yingxiong");
	me->add_temp("apply/courage", -level);
	message_combatd(HIY"$N突然感到心底一阵失落：“历代英雄，都归孤冢。”一念及此，顿时意兴萧然。\n" NOR, me);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗费自己的内力
		大幅提高自己的胆识

	出手要求：
		毒龙大法50级
		英雄三招60级
		自身为男性
		内力300
HELP
	);
	return 1;
}

