// qudu.c
// Last Modified by winder on Mar. 10 2000
/* 下列为本泥巴的毒：
白驼派：bt_poison 怪蛇毒
	cold_poison 寒毒
	hot_poison 热毒
	snake_poison 蛇毒
星宿派：fushi_poison 腐尸毒
	poison_sandu 散毒反噬
	slumber_poison 蒙汗药
	sanxiao_poison 三笑逍遥散
	xx_poison 星宿掌毒
五毒教：chanchu_poison 蟾蜍毒
	snake_poison 蛇毒
	wugong_poison 蜈蚣毒
	wuxing_poison 无形毒
	xiezi_poison 蝎子毒
	zhizhu_poison 蜘蛛毒
绝情谷：qinghua_poison 情花毒
明教：	ice_poison 寒冰绵掌毒
逍遥派：ss_poison 生死符
古墓派：ice_sting 冰魄银针毒
云龙门：zhua_poison 凝血神抓
雪山派：dashouyin 大手印
神龙岛：flower_poison 断肠花毒
杭州：	scorpion_poison 蝎子毒
其他：	ill_dongshan 冻伤
	ill_fashao 发烧
	ill_kesou 咳嗽
	ill_shanghan 伤寒
	ill_zhongshu 中暑
未用：	bing_poison 冰晶毒
	cuff_power 拳后劲
	iceshock 意寒掌毒
	rose_poison 火玫瑰毒
*/
#include <ansi.h>

int exert(object me, object target)
{
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/qudu") &&
  !me->query("can_perform/hamagong/qudu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的内功中没有这种功能。");

	if( me->is_fighting() )
		return notify_fail("战斗中运功驱毒？找死吗？\n");
	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够。\n");
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已经受伤过重，一运真气便有生命危险！\n");
	if ((int)me->query_skill("xidu-poison", 1) < 50)
		return notify_fail("你对“西毒毒技”还不是很精通。\n");
	if ((int)me->query_skill("hamagong", 1) < 50)
		return notify_fail("你的蛤蟆功修为还不够。\n");

	if ((int)me->query_condition("bt_poison") > 0 ||
		me->query_condition("cold_poison") > 0 ||
		me->query_condition("hot_poison") > 0 ||
		me->query_condition("snake_poison") > 0 ||
		me->query_condition("fushi_poison") > 0 ||
		me->query_condition("slumber_poison") > 0 ||
		me->query_condition("xx_poison") > 0 ||
		me->query_condition("chanchu_poison") > 0 ||
		me->query_condition("wugong_poison") > 0 ||
		me->query_condition("xiezi_poison") > 0 ||
		me->query_condition("zhizhu_poison") > 0 ||
		me->query_condition("ice_sting") > 0 ||
		me->query_condition("scorpion_poison") > 0)
	{
		write(HIG"你倒运气息，头下脚上，气血逆行，将毒气从进入身子之处逼了出去。\n"NOR);
		message("vision", HIW+me->name()+"身上白气一现即消，张口哼了一声。\n吐出一口"HIY"金灿灿的瘀血"HIW"，一滴滴"BLK"黑血"HIW"从伤口慢慢渗出。\n"NOR,environment(me));
		me->clear_condition("bt_poison");
		me->clear_condition("cold_poison");
		me->clear_condition("hot_poison");
		me->clear_condition("snake_poison");
		me->clear_condition("fushi_poison");
		me->clear_condition("slumber_poison");
		me->clear_condition("xx_poison");
		me->clear_condition("chanchu_poison");
		me->clear_condition("wugong_poison");
		me->clear_condition("xiezi_poison");
		me->clear_condition("zhizhu_poison");
		me->clear_condition("ice_sting");
		me->clear_condition("scorpion_poison");
		me->add("neili", -500);
		me->start_busy(6);
		return 1;
	}
	else
	return notify_fail("你深深吸了口气，口中“咕咕。。。”地叫了几声。\n"); 
}

int help(object me)
{
	write(WHT"\n蛤蟆功之驱毒："NOR"\n");
	write(@HELP

	使用功效：
		驱除体内毒素，对下列毒有效：
		白驼怪蛇毒、寒毒、热毒、蛇毒、腐尸毒、蒙汗药、
		星宿掌毒、蟾蜍毒、蜈蚣毒、蝎子毒、蜘蛛毒、冰魄银针毒

	出手要求：
		蛤蟆功50级
		西毒毒技50级
		内力500
HELP
	);
	return 1;
}

