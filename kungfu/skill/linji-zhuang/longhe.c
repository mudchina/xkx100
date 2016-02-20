// longhe.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/longhe") &&
  !me->query("can_perform/linji-zhuang/longhe") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (me->query_temp("ljlonghe"))
		return notify_fail("你已经在运龙鹤庄了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是处女纯阴之体，不能运龙鹤庄！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运龙鹤庄！\n");

	if( (int)me->query("neili") < 300)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 90)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIR "$N坐了下来运起龙鹤庄，把全身上下拍打了一遍，觉得全身充满力量，....
就想发泄出去，和谁过过招一样。\n" NOR, me);
	me->add("neili", -300);
	me->add("eff_jing", -15);
	me->add("jing", -20);
	me->set_temp("ljlonghe", 1);
	me->add_temp("apply/constitution", (int)skill/30);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/30:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/constitution",-count);
	me->delete_temp("ljlonghe");
	tell_object(me, 
HIB "忽然你觉得全身懒洋洋的，连个小指头也不想动了，原来你的
龙鹤庄收功了！\n" NOR );
}

int help(object me)
{
	write(WHT"\n临济十二庄之龙鹤庄："NOR"\n");
	write(@HELP

	使用功效：
		临时提高根骨

	出手要求：
		临济十二庄90级
		内力300
		处女纯阴之体
HELP
	);
	return 1;
}

