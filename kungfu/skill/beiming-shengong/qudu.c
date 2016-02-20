// qudu.c
// Last Modified by sir on 5.4.2002

#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/qudu") &&
  !me->query("can_perform/beiming-shengong/qudu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( (!target))
		return notify_fail("你要用真气为谁驱毒？\n");

	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功驱毒！\n");

	if( me->is_busy() )
		return notify_fail("你现在正忙着呢，哪有空运功？\n");

	notify_fail("不是你要抓的人，凑什么热闹！\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;

	if( target->is_busy())
		return notify_fail(target->name()+"现在正忙着呢！\n");

	if( !target->query_condition("ss_poison"))
		return notify_fail(target->name()+"并没有中生死符！\n");
		
	if( (int)me->query_skill("beiming-shengong",1) < 50 )
		return notify_fail("你的北冥神功修为不够。\n");

	if( (int)me->query("max_neili") < 150 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("neili") < 150)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("force") < (int)target->query_skill("force") / 3 )
		return notify_fail( target->name() + "中毒已经深，以你的内功修为恐怕解不了他的生死符！\n");

	if (me != target)
	message_combatd( HIC"$N坐了下来运起北冥神功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n过了不久，$N额头上冒出豆大的汗珠，$n指尖渗出一缕白色雾气，脸色看起来红润多了。\n" NOR, me, target );
    else
    message_vision( HIC"$N右掌以阳刚之气急拍，左掌以阴柔之力缓运，开始自行化解生死符之毒....\n\n过了许久，$N只觉“阴陵泉”穴上一团窒滞之意霍然而解，关节灵活，说不出的舒适。\n"NOR,me);

//	target->set("qi", (int)target->query("eff_qi"));
	target->clear_condition("ss_poison",0);

	me->add("neili", -100);
	me->start_busy(1);
	if ( userp(target)) target->start_busy(2);

	return 1;
}

int help(object me)
{
	write(WHT"\n北冥神功之驱毒："NOR"\n");
	write(@HELP

	使用功效：
		解生死符

	出手要求：
		北冥神功50级
	        内力150
	        双方基本内功悬殊不大
HELP
	);
	return 1;
}

