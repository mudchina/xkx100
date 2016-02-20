// fengyun.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fengyun") &&
  !me->query("can_perform/linji-zhuang/fengyun") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (me->query_temp("ljfengyun"))
		return notify_fail("你已经在运风云庄了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是处女纯阴之体，不能运风云庄！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运风云庄！\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 120)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIC "$N坐了下来运起风云庄，缓缓将内力运到脚心涌泉穴，....
稍许，觉得一股暖流自足底涌汹涌而上，顿时觉得身轻如燕，跃跃欲飞。\n" NOR, me);
	me->add("neili", -400);
	me->add("jing", -20);
	me->set_temp("ljfengyun", 1);
	me->add_temp("apply/dexerity", (int)skill/40);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/dexerity",-count);
	me->delete_temp("ljfengyun");
	tell_object(me, 
HIB"忽然你觉得一股浊气自腰间猛向下沉去，顿时双足如灌铅般沉
重，原来你的风云庄收功了！\n" NOR );
}

int help(object me)
{
	write(WHT"\n临济十二庄之风云庄："NOR"\n");
	write(@HELP

	使用功效：
		临时提高身法

	出手要求：
		临济十二庄120级
		内力400
		处女纯阴之体
HELP
	);
	return 1;
}

