// zhixin.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zhixin") &&
  !me->query("can_perform/linji-zhuang/zhixin") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (me->query_temp("ljzhixin"))
		return notify_fail("你已经在运之心庄了！\n");

	if (me->query("gender") != "女性")
		return notify_fail("你不是纯阴之体，不能运之心庄！\n");

//	if (me->query("sex/number") )
//		return notify_fail("你不是处女之身，不能运幽冥庄！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运之心庄！\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIY "$N坐了下来运起之心庄，将手掌在脑门上磕了两下，顿觉灵台清明，....
站了起来，发现脑袋瓜灵光了不少。\n" NOR, me );
	me->add("neili", -200);
	me->add("eff_jing", -10);
	me->add("jing", -20);
	me->add_temp("apply/intelligence", (int)skill/40);
	me->set_temp("ljzhixin", 1);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/intelligence",-count);
	me->delete_temp("ljzhixin");
	tell_object(me, 
HIB "忽然你头脑里感到一阵空白，原来你的之心庄收功了，你顿时
觉得自己还是个大笨木瓜！\n" NOR );
}

int help(object me)
{
	write(WHT"\n临济十二庄之之心庄："NOR"\n");
	write(@HELP

	使用功效：
		临时提高悟性

	出手要求：
		临济十二庄60级
		内力200
		处女纯阴之体
HELP
	);
	return 1;
}

