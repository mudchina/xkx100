// tuwu.c 金蛇吐雾
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "金蛇吐雾"
inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;
	object weapon;
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
		
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "jinshe zhui" ||
		weapon->query("ownmake") == 1)
		return notify_fail("你没用金蛇锥，不能使用绝招！\n");

	bskill = "throwing";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"不够娴熟，不会使用"+PNAME+"。\n");

	if (me->query_temp("jinshe/tuwu"))
		return notify_fail("你才用的金蛇吐雾，没法接着就出招。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");

	skill = me->query_skill(bskill, 1);
	me->add("neili", -200);

	if (random(me->query_skill("force"))>target->query_skill("force")/2 ||
	    random(me->query("combat_exp"))>(int)target->query("combat_exp")/3 )
	{
		me->start_busy(2);
		target->start_busy(random(3));
		target->receive_damage("qi", 200,me);
		message_combatd(
HIY "只听一阵狂风扫叶般的声响中，$N"HIY"手中的"YEL"金蛇锥"HIY"闪出夺目的光芒，闪耀得
$n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
		me->set_temp("jinshe/tuwu", 1);
		me->set_temp("noliving/cimu",1);
		target->set_temp("block_msg/all",1);
		call_out("tuwu_end", (int) skill/30, me, target);
	} else
	{
		me->start_busy(2);
		message_combatd("$N使出一招“金蛇吐雾”，可惜锥未发出，被$n制了
先机。顿时手脚大乱。\n", me, target);
	}
	return 1;
}
void tuwu_end(object me, object target)
{
//	target->enable_player();
  if (objectp(target))
  {
	  message_combatd("$N慢慢恢复了视力，终于睁开了眼。\n", target);
	  target->set_temp("block_msg/all", 0);
	  target->delete_temp("noliving");
  }
  if (objectp(me))
	me->delete_temp("jinshe/tuwu");
	return;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}
int sp() {return 1;}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		损伤对方气血
		迟滞对方出手
		使对方暂时失明

	出手要求：
		金蛇锥法100级
		内力300
HELP
	);
	return 1;
}

