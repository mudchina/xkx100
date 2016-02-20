// guimei.c 鬼魅身法
// Last Modified by winder on Oct. 28 2000

#include <ansi.h>

inherit F_SSERVER;

int exert(object me, object target)
{
	string msg;
	int skill = me->query_skill("kuihua-xinfa",1); 

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/guimei") &&
  !me->query("can_perform/kuihua-xinfa/guimei") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( me->query_temp("bixie/guimei"))
		return notify_fail("你已经在运用鬼魅身法了吧？\n");

//	if( !target || !target->is_character() || !me->is_fighting(target) )
//		return notify_fail("你一个人跳来跳去干什么？\n");

	if( !me->query_temp("murong/xingyi") )
	{
		if((int)me->query_skill("kuihua-xinfa", 1) < 100)
			return notify_fail(HIY "你的葵花心法修为不够。\n" NOR);
		if((int)me->query_skill("bixie-jian", 1) < 120)
			return notify_fail(HIY "你的辟邪剑法不够熟练。\n" NOR);
	}
	if((int)me->query("neili") < 200)
		return notify_fail(HIY "你现在真气不足。\n" NOR);

	msg = HIC"但见$N的身形如鬼如魅，飘忽来去，直似轻烟。衣袖带风，却不发出半点声息。\n"NOR;
	message_combatd(msg, me);
	me->add("neili", -200);
	me->set_temp("bixie/guimei", 1);
	me->add_temp("apply/dexerity", (int)skill/30);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/30:),skill/4);
	return 1;
}

void remove_effect(object me, int count)
{
//	me->delete_temp("apply/dexerity");
  me->add_temp("apply/dexerity",-count);
	me->delete_temp("bixie/guimei");
	tell_object(me,HIY"你觉得一股浊气沉下丹田，你的鬼魅身法收功了！\n" NOR);
}

int help(object me)
{
	write(WHT"\n葵花心法之鬼魅身法："NOR"\n");
	write(@HELP

	使用功效：
		暂时提高身法

	出手要求：
		葵花心法100级
		辟邪剑法120级
		内力200
HELP
	);
	return 1;
}

