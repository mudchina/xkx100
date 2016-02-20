// youming.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	object obj;
	int skill;
	
	seteuid(getuid());
	skill = (int)me->query_skill("linji-zhuang",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/youming") &&
  !me->query("can_perform/linji-zhuang/youming") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if (!wizardp(me))
	{
	if (me->query("gender") != "女性")
		return notify_fail("你不是纯阴之体，不能运幽冥庄！\n");

	if (me->query("sex/number") )
		return notify_fail("你不是处女之身，不能运幽冥庄！\n");

	if( me->is_busy() )
		return notify_fail("你现在太累！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法运幽冥庄！\n");

	if( !me->query("dietime"))
		return notify_fail("你未历幽冥，恐怕难运此庄。\n");

	if( me->query("dietime") < time() - 300)
		return notify_fail("你离开幽冥已久，已无幽冥灵气。\n");

	if( (int)me->query("neili") < 1000)
		return notify_fail("你的真气不够。\n");

	if( me->query("jing") < 100 || me->query("qi") < 200)
		return notify_fail("你的精气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 180)
		return notify_fail("你的临济庄级别不够。\n");
	}
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIG"$N坐了下来运起"HIB"幽冥庄"HIG"，双掌抱球，两股"MAG"紫气"HIG"从掌心中渐渐透出，在两\n掌之间交汇激荡，发出"HIY"风雷之声"HIG"。于是"MAG"紫气"HIG"中慢慢投射出"HIW"白光"HIG"，又缓缓\n地"HIR"耀目"HIG"起来，终于一声清脆的爆响，$N的双掌猛地合在了一起！$N翻开\n手掌，呵护着一粒晶莹剔透的"HIW"丹丸。\n" NOR, me );
	message_vision("\n$N身子一歪坐在地上，实在太累了，爬不起来。\n",me);
	me->add("neili", -1000);
	me->receive_wound("jing", 100);
	me->receive_wound("qi", 100);
	obj = new("/clone/medicine/nostrum/guiyuandan");
	obj->set("owner",me);
	obj->move(me);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n临济十二庄之幽冥庄："NOR"\n");
	write(@HELP

	使用功效：
		练制归元丹

	出手要求：
		临济十二庄180级
		内力1000
		精气100
		气血200
		处女纯阴之体
HELP
	);
	return 1;
}

