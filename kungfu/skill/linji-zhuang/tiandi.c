// tiandi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/tiandi") &&
  !me->query("can_perform/linji-zhuang/tiandi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (me->query_temp("ljtiandi"))
		return notify_fail("你已经在运天地庄了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是处女纯阴之体，不能运天地庄！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运天地庄！\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIM "$N坐了下来运起天地庄，将手掌贴在脸上，缓缓地将真气轻轻扑在脸上....
过了不久，$N的脸上亮出晶莹的颜色，缓缓睁开的眼里透出青春的气息。\n" NOR,
	me );
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
	me->set_temp("ljtiandi", 1);
	me->add_temp("apply/personality", (int)skill/20);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/20:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/personality",-count);
	me->delete_temp("ljtiandi");
	tell_object(me, 
HIB "忽然你心里头感到一阵失落，原来你的天地庄收功了，你顿时
倍感红颜老去之叹！\n" NOR );
}

int help(object me)
{
	write(WHT"\n临济十二庄之天地庄："NOR"\n");
	write(@HELP

	使用功效：
		临时提高容貌

	出手要求：
		临济十二庄30级
		内力100
		处女纯阴之体
HELP
	);
	return 1;
}

