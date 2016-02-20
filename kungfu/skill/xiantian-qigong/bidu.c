// bidu.c
// Last Modified by Winder on Oct. 20 2000
#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3, con4, con5, con6;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/bidu") &&
  !me->query("can_perform/xiantian-qigong/bidu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	con1 = me->query_condition("snake_poison");
	con2 = me->query_condition("scorpion_poison");
	con3 = me->query_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	con5 = me->query_condition("zhua_poison");
	con6 = me->query_condition("ice_poison");

	if(con1< 1 && con2< 1 && con3< 1 &&con4 < 1 && con5< 1 && con6< 1)
		return notify_fail("你坐下运功逼毒。不过好象没法逼出什么来。\n");
	if( me->is_fighting() )
		return notify_fail("战斗中运功逼毒？嫌死不快是吗？\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 80)
		return notify_fail("你的先天气功修为还不够。\n");

	message("vision", 
	HIY+me->name()+"盘膝坐下，缓引真气，运功逼毒。只见一团"HIW"白雾"HIY"渐渐笼住"+me->name()+"的面目。\n良久，一滴"HIM"紫血"HIY"从"+me->name()+"的右手小指尖缓缓滴了下来。\n" NOR,
		environment(me));

	me->add("neili", -300);
	me->add("qi", 10 + (int)me->query_skill("force")/5 );
	if(me->query("qi") > me->query("eff_qi"))
		me->set("qi", me->query("eff_qi"));
	me->start_busy(4);
	if (con1) me->clear_condition("snake_poison");
	if (con2) me->clear_condition("scorpion_poison");
	if (con3) me->clear_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	if (con5) me->clear_condition("zhua_poison");
	if (con6) me->clear_condition("ice_poison");
	return 1;
}
int help(object me)
{
	write(WHT"\n先天气功之逼毒"NOR"\n");
	write(@HELP

	使用功效：
		运功逼出体内毒素，对下列毒有效：
		蛇毒、蝎子毒、星宿掌毒、凝血神抓

	出手要求：
		先天气功80级
		内力500
HELP
	);
	return 1;
}

