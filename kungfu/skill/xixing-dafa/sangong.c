// sangong.c

#include <ansi.h>
void mess(object me);

int exert(object me, object target)
{		
//  if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/sangong") &&
//  !me->query("can_perform/xixing-dafa/sangong") && 
//  !me->query_temp("murong/xingyi"))
//   return notify_fail("你所使用的内功中没有这种功能。");
	if( me->is_fighting() ) return notify_fail("战斗中散功？找死吗？\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if((int)me->query_skill("xixing-dafa", 1) > 20)
		return notify_fail("你现在不必散功。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2)
		return notify_fail("你受伤过重，只怕一运真气便有生命危险！\n");

	message_vision( HIY"$N坐下来开始散功：“当令丹田常如空箱，恒似深谷，空箱可贮物，深谷可容水。若有内息，散之于任脉诸穴。”\n" NOR, me);
	me->start_busy(5);
	me->start_call_out( (: call_other,__FILE__,"sangong",me :),5);
	return 1;
}
void sangong(object me)
{
	object ob;
	message_vision(HIG"$N顿时觉得丹田有气，散之任脉，如竹中空，似谷恒虚……\n"NOR,me);
	me->set("max_neili", 0);
	me->set("neili", 0);
	return;
}

int help(object me)
{
	write(WHT"\n吸星大法之散功"NOR"\n");
	write(@HELP

	使用功效：
		练习吸星大法必须经过散功，散去全身内力

	出手要求：
		吸星大法小于10级
HELP
	);
	return 1;
}

